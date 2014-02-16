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
            m_plateau[x][y]=CouleurPion::aucuneCouleur;
        }
    }
    m_joueurVictorieux=CouleurPion::aucuneCouleur;
    QObject::connect(&m_grilleJeu, SIGNAL(sigPionClique(int, int)), this, SLOT(slotPionClique(int, int) ) );

    QObject::connect(this, SIGNAL(joueurNoirPionClique(Coup)), &m_joueur1, SLOT(slotCoupClique(Coup) ) );
    QObject::connect(this, SIGNAL(joueurBlancPionClique(Coup)), &m_joueur2, SLOT(slotCoupClique(Coup) ) );

    m_joueur1.setCouleur(CouleurPion::noir);
    m_joueur2.setCouleur(CouleurPion::blanc);

    m_joueur1.setjeu(this);
    m_joueur2.setjeu(this);

}

void Jeu::getCoupEtJoue(Joueur &joueur)
{
    while (1) {
        Coup coup = joueur.getCoup();

        if (jouerCoup(coup) == INVALIDE) {
            cerr << "coup invalide! Réessayez:" << endl;
        }
        else {
            break;
        }
    }
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
    if (m_plateau[coup.x][coup.y] != CouleurPion::aucuneCouleur) {
        return INVALIDE;
    }

    m_plateau[coup.x][coup.y]=coup.couleur;
    coupsJoues.push_back(coup);
    regles();
    return SUCCES;
}

bool Jeu::fin(){
    if(m_joueurVictorieux==CouleurPion::aucuneCouleur){
        return false;
    } else {
        return true;
    }
}

// renvoye le nombre de pions de la couleur donnée alignés dans la direction (d1,d2) en partant de la case (x,y)
int Jeu::lireligne(int px,
                   int py,
                   int dx, /* +1, -1 ou 0 */
                   int dy,/* +1, -1 ou 0*/
                   CouleurPion couleur /* 1 ou 2 */){
    if (px < 0 || px > LARGEUR_PLATEAU - 1) {
        cerr << "Jeu::lireligne appellée avec paramètre x invalide" << endl;
        return 0;
    }
    if (py < 0 || py > HAUTEUR_PLATEAU - 1) {
        cerr << "Jeu::lireligne appellée avec paramètre y invalide" << endl;
        return 0;
    }

    int cpt=0;

    while(m_plateau[px][py]==couleur){
        cpt++;
        px+=dx;
        py+=dy;

        /* gère les coups en bord de plateau */
        if (px < 0 || px > LARGEUR_PLATEAU -1) {
            break;
        }
        if (py < 0 || py > HAUTEUR_PLATEAU -1) {
            break;
        }
    }

    return cpt;
}

CouleurPion Jeu::oppose(CouleurPion couleur){
    if(couleur==CouleurPion::blanc){
        return CouleurPion::noir;
    }
    else if (couleur==CouleurPion::noir){
        return CouleurPion::blanc;
    }
    else {
        cerr << "couleur invalide";
        return CouleurPion::aucuneCouleur;
    }
}

void Jeu::regles(){
    if (coupsJoues.size() == 0){
        cerr << "coups joués vide!";
        return;
    }
    Coup dernierCoupJoue = coupsJoues.back();

    int dernierCoupX = dernierCoupJoue.x;
    int dernierCoupY = dernierCoupJoue.y;
    CouleurPion joueurDernierCoup = dernierCoupJoue.couleur;

    // détermine si 5 pierres sont alignées
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0){
                continue;
            }
            if(lireligne(dernierCoupX+i, dernierCoupY+j, i, j, joueurDernierCoup) +
               lireligne(dernierCoupX-i, dernierCoupY-j, -1*i, -1*j, joueurDernierCoup)  >=4){
                //VICTOIRE
                cout<<"joueur "<<joueurDernierCoup<<" a gagné la partie (5 pierres)"<<endl;
                m_joueurVictorieux=joueurDernierCoup;
            }
        }
    }

    //mange pions si nécessaire
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0){
                continue;
            }
            //cout<<"nb l : "<<i<<j<<" : "<<lireligne(cx+i,cy+j, i, j, oppose(joueurDernierCoup))<<endl;
            if(lireligne(dernierCoupX+i,dernierCoupY+j, i, j, oppose(joueurDernierCoup))==2){
                if (dernierCoupX +3*i < 0 ||
                    dernierCoupX+3*i > LARGEUR_PLATEAU - 1 ||
                    dernierCoupY+3*j < 0 ||
                    dernierCoupY+3*j > LARGEUR_PLATEAU - 1) {
                    //en partant du bord du plateau, il y a deux pierres d'une couleur puis une troisième de l'autre couleur
                    //il n'y a pas de point à manger.
                    continue;
                }
                if(m_plateau[dernierCoupX+3*i][dernierCoupY+3*j]==joueurDernierCoup){
                    //ON MANGE
                    cout<<"mangé!"<<endl;
                    m_plateau[dernierCoupX+i][dernierCoupY+j]=CouleurPion::aucuneCouleur;
                    m_plateau[dernierCoupX+2*i][dernierCoupY+2*j]=CouleurPion::aucuneCouleur;
                    if(joueurDernierCoup==CouleurPion::noir){
                        m_prisonniersJoueurNoir+=2;
                    } else {
                        m_prisonniersJoueurBlanc+=2;
                    }
                    if(m_prisonniersJoueurNoir==10){
                        cout<<"JOUEUR 1 A GAGNE avec 10 prisonniers"<<endl;
                        m_joueurVictorieux=CouleurPion::noir;
                    }
                    if(m_prisonniersJoueurBlanc==10){
                        cout<<"JOUEUR 2 A GAGNE avec 10 prisonniers"<<endl;
                        m_joueurVictorieux=CouleurPion::blanc;
                    }
                }
            }
        }
    }
    if(m_joueurVictorieux!=CouleurPion::aucuneCouleur){
        cout<<"joueur "<<m_joueurVictorieux<<" a gagné"<<endl;
    }
}

void Jeu::slotPionClique(int xNumero, int yNumero)
{
    Coup coupClique;
    coupClique.x = xNumero;
    coupClique.y = yNumero;
    if (coupsJoues.size() == 0) {
        //joueur noir commence la partie
        coupClique.couleur = CouleurPion::noir;
        emit joueurNoirPionClique(coupClique);
        return;
    }

    Coup dernierCoupJoue = coupsJoues.back();

    if (dernierCoupJoue.couleur == CouleurPion::noir){
        coupClique.couleur = CouleurPion::blanc;
        emit joueurBlancPionClique(coupClique);
    }
    else{
        coupClique.couleur = CouleurPion::noir;
        emit joueurNoirPionClique(coupClique);
    }
}

//ACCESSEURS :

CouleurPion Jeu::getplateau(int x, int y){
    return m_plateau[x][y];
}

int Jeu::getPrisonniersJ1(){
    return m_prisonniersJoueurNoir;
}

int Jeu::getPrisonniersJ2(){
    return m_prisonniersJoueurBlanc;
}

std::vector<Coup> &Jeu::getcoupsJoues(){
    return coupsJoues;
}
