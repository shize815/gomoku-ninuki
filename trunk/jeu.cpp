#include "jeu.h"
#include "joueur.h"

#include <stdlib.h>


using namespace std;

Jeu::Jeu(GrilleJeu &grilleJeu, Joueur &joueur1, Joueur &joueur2) :
    m_grilleJeu(grilleJeu), m_joueur1(joueur1), m_joueur2(joueur2)
{
    m_plateau.resize(LARGEUR_PLATEAU);
    for(int it=0; it<LARGEUR_PLATEAU; it++){
        m_plateau[it].resize(HAUTEUR_PLATEAU);
    }
    for(int x=0; x<LARGEUR_PLATEAU; x++){
        for(int y=0; y<HAUTEUR_PLATEAU; y++){
            m_plateau[x][y]=0;
        }
    }
    m_joueurVictorieux=0;
    QObject::connect(&m_grilleJeu, SIGNAL(sigPionClique(int, int)), this, SLOT(slotPionClique(int, int) ) );

    QObject::connect(this, SIGNAL(joueur1PionClique(Coup)), &m_joueur1, SLOT(slotCoupClique(Coup) ) );
    QObject::connect(this, SIGNAL(joueur2PionClique(Coup)), &m_joueur2, SLOT(slotCoupClique(Coup) ) );

    m_joueur1.setNumero(1);
    m_joueur2.setNumero(2);

    m_joueur1.setjeu(this);
    m_joueur2.setjeu(this);

}

void Jeu::getCoupEtJoue(Joueur &joueur)
{
    Resultat res = SUCCES;
    do {
        Coup coup = joueur.getCoup();
        res = jouerCoup(coup);
        if (res != SUCCES) {
            cerr << "coup invalide! Réessayez:" << endl;
        }
    } while (res != SUCCES);
}

void Jeu::jouePartie()
{
    while(!fin()){
        m_grilleJeu.affiche(m_plateau, m_joueurVictorieux);
        getCoupEtJoue(m_joueur1);
        m_grilleJeu.affiche(m_plateau, m_joueurVictorieux);
        getCoupEtJoue(m_joueur2);
    }
    /* affiche le plateau victorieux */
    m_grilleJeu.affiche(m_plateau, m_joueurVictorieux);
}



Resultat Jeu::jouerCoup(Coup coup){
    if (coup.x > LARGEUR_PLATEAU || coup.y > HAUTEUR_PLATEAU) {
        return INVALIDE;
    }
    if (coup.x < 0 || coup.y < 0) {
        return INVALIDE;
    }
    if (m_plateau[coup.x][coup.y] != 0) {
        return INVALIDE;
    }

    m_plateau[coup.x][coup.y]=coup.numeroJoueur;
    coupsJoues.push_back(coup);
    regles();
    return SUCCES;
}

bool Jeu::fin(){
    if(m_joueurVictorieux==0){
        return false;
    } else {
        return true;
    }
}

// renvoye le nombre de pions de la couleur donn�e align�s dans la direction (d1,d2) en partant de la case (x,y)
int Jeu::lireligne(int px,
                   int py,
                   int dx, /* +1, -1 ou 0 */
                   int dy,/* +1, -1 ou 0*/
                   int couleur /* 1 ou 2 */){
    if (px < 0 || px > LARGEUR_PLATEAU - 1) {
        cerr << "Jeu::lireligne appell�e avec param�tre x invalide" << endl;
        return 0;
    }
    if (py < 0 || py > HAUTEUR_PLATEAU - 1) {
        cerr << "Jeu::lireligne appell�e avec param�tre y invalide" << endl;
        return 0;
    }

    int cpt=0;
    //cout << "pos(x" << px << ",y" << py << "), coul(" << couleur << ") : " << m_plateau[px][py] << endl;
    while(m_plateau[px][py]==couleur){
        cpt++;
        px+=dx;
        py+=dy;

        /* g�re les coups en bord de plateau */
        if (px < 0 || px > LARGEUR_PLATEAU -1) {
            break;
        }
        if (py < 0 || py > HAUTEUR_PLATEAU -1) {
            break;
        }
    }

    return cpt;
}

int Jeu::oppose(int couleur){
    if(couleur==2){
        return 1;
    }
    if(couleur==1){
        return 2;
    }
    return 0;
}

void Jeu::regles(){
    if (coupsJoues.size() == 0){
        std::cerr << "coups joués vide!";
    }
    Coup dernierCoupJoue = coupsJoues.back();

    int dernierCoupX = dernierCoupJoue.x;
    int dernierCoupY = dernierCoupJoue.y;
    int joueurDernierCoup = dernierCoupJoue.numeroJoueur;

    // d�termine si 5 pierres sont align�es
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0){
                continue;
            }
            if(lireligne(dernierCoupX+i, dernierCoupY+j, i, j, joueurDernierCoup) +
               lireligne(dernierCoupX-i, dernierCoupY-j, -1*i, -1*j, joueurDernierCoup)  >=4){
                //VICTOIRE
                cout<<"joueur "<<joueurDernierCoup<<" a gagn� la partie"<<endl;
                m_joueurVictorieux=joueurDernierCoup;
            }
        }
    }

    //mange pions si n�cessaire
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0){
                continue;
            }
            //cout<<"nb l : "<<i<<j<<" : "<<lireligne(cx+i,cy+j, i, j, oppose(joueurDernierCoup))<<endl;
            if(lireligne(dernierCoupX+i,dernierCoupY+j, i, j, oppose(joueurDernierCoup))==2){
                //ON MANGE
                if(m_plateau[dernierCoupX+3*i][dernierCoupY+3*j]==joueurDernierCoup){
                    cout<<"mang�!"<<endl;
                    m_plateau[dernierCoupX+i][dernierCoupY+j]=0;
                    m_plateau[dernierCoupX+2*i][dernierCoupY+2*j]=0;
                    if(joueurDernierCoup==1){
                        p1+=2;
                    } else {
                        p2+=2;
                    }
                    if(p1==10){
                        cout<<"JOUEUR 1 A GAGNE avec 10 prisonniers"<<endl;
                        m_joueurVictorieux=1;
                    }
                    if(p2==10){
                        cout<<"JOUEUR 2 A GAGNE avec 10 prisonniers"<<endl;
                        m_joueurVictorieux=2;
                    }
                }
            }
        }
    }
    if(m_joueurVictorieux!=0){
        cout<<"joueur "<<m_joueurVictorieux<<" a gagn�"<<endl;
    }
}

void Jeu::slotPionClique(int xNumero, int yNumero)
{
    Coup coupClique;
    coupClique.x = xNumero;
    coupClique.y = yNumero;
    if (coupsJoues.size() == 0) {
        //joueur1 commence la partie
        coupClique.numeroJoueur = 1;
        emit joueur1PionClique(coupClique);
        return;
    }

    Coup dernierCoupJoue = coupsJoues.back();

    if (dernierCoupJoue.numeroJoueur == 1){
        coupClique.numeroJoueur = 2;
        emit joueur2PionClique(coupClique);
    }
    else{
        coupClique.numeroJoueur = 1;
        emit joueur1PionClique(coupClique);
    }
}

//ACCESSEURS :

int Jeu::getplateau(int x, int y){
    return m_plateau[x][y];
}

int Jeu::getp1(){
    return p1;
}

int Jeu::getp2(){
    return p2;
}

std::vector<Coup> &Jeu::getcoupsJoues(){
    return coupsJoues;
}
