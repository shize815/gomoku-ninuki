#include "jeu.h"
#include "joueur.h"
#include "joueurIA.h"

#include <stdlib.h>


using namespace std;

Jeu::Jeu(){
    plateau.resize(LARGEUR_PLATEAU);
    for(int it=0; it<LARGEUR_PLATEAU; it++){
        plateau[it].resize(HAUTEUR_PLATEAU);
    }
    for(int x=0; x<LARGEUR_PLATEAU; x++){
        for(int y=0; y<HAUTEUR_PLATEAU; y++){
            plateau[x][y]=0;
        }
    }
    joueurVictorieux=0;
}

Jeu::~Jeu(){

}

void Jeu::getCoupEtJoue(Joueur &joueur, Jeu &jeu)
{
    Resultat res = SUCCES;
    do {
        Coup coup;
        joueur.getCoup(&coup);
        res = jeu.jouerCoup(coup);
        if (res != SUCCES) {
            cerr << "coup invalide! Réessayez:" << endl;
        }
    } while (res != SUCCES);
}

void Jeu::jouePartie(Joueur &joueur1, Joueur &joueur2)
{
    joueur1.setNumero(1);
    joueur2.setNumero(2);

    Jeu jeu;
    joueur1.setjeu(&jeu);
    joueur2.setjeu(&jeu);

    Coup coup;
    coup.x = 0;
    coup.y = 0;
    coup.numeroJoueur = joueur1.getNumero();

    jeu.jouerCoup(coup); /* TODO pour l'instant on est obligé de jouer ce premier coup parce que l'IA
                            ne peut que répondre à un coup */
    while(!jeu.fin()){
        jeu.affiche();
        getCoupEtJoue(joueur1, jeu);
        getCoupEtJoue(joueur2, jeu);
    }
    /* affiche le plateau victorieux */
    jeu.affiche();
}

void Jeu::affiche(){
    //numéros des colonnes affichés en haut
    cout <<"   ";
    for (int x=0; x<LARGEUR_PLATEAU; x++){
        if (x<10){
            cout<<x<<"  ";
        } else{
            cout<<x<<" ";
        }
    }
    cout << endl;

    //reste du plateau
    for(int y=0; y<HAUTEUR_PLATEAU; y++){
        if(y<10){
            cout<<y<<"  ";
        } else {
            cout<<y<<" ";
        }

        for(int x=0; x<LARGEUR_PLATEAU; x++){

            if(plateau[x][y]==0){
                cout<<".  ";
            }
            else if(plateau[x][y]==1){
                cout<<"O  ";
            }
            else if(plateau[x][y]==2){
                cout<<"X  ";
            }
        }
        cout<<endl;
    }

    if(joueurVictorieux!=0){
        cout<<"joueur "<<joueurVictorieux<<" a gagné"<<endl;
    }
}

Resultat Jeu::jouerCoup(Coup coup){
    if (coup.x > LARGEUR_PLATEAU || coup.y > HAUTEUR_PLATEAU) {
        return INVALIDE;
    }
    if (coup.x < 0 || coup.y < 0) {
        return INVALIDE;
    }
    if (plateau[coup.x][coup.y] != 0) {
        return INVALIDE;
    }

    plateau[coup.x][coup.y]=coup.numeroJoueur;
    coupsJoues.push_back(coup);
    regles();
    return SUCCES;
}

bool Jeu::fin(){
    if(joueurVictorieux==0){
        return false;
    } else {
        return true;
    }
}

// renvoye le nombre de pions de la couleur donnée alignés dans la direction (d1,d2) en partant de la case (x,y)
int Jeu::lireligne(int px, int py, int d1, int d2, int couleur){
    if (px < 0 || px > LARGEUR_PLATEAU - 1) {
        cerr << "Jeu::lireligne appellée avec paramètre x invalide" << endl;
        return 0;
    }
    if (py < 0 || py > HAUTEUR_PLATEAU - 1) {
        cerr << "Jeu::lireligne appellée avec paramètre y invalide" << endl;
        return 0;
    }

    int cpt=0;
    cout << "pos(x" << px << ",y" << py << "), coul(" << couleur << ") : " << plateau[px][py] << endl;
    while(plateau[px][py]==couleur){
        cpt++;
        px+=d1;
        py+=d2;

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
    Coup dernierCoupJoue = coupsJoues.back();

    int dernierCoupX = dernierCoupJoue.x;
    int dernierCoupY = dernierCoupJoue.y;
    int joueurDernierCoup = dernierCoupJoue.numeroJoueur;

    // détermine si 5 pierres sont alignées
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0){
                continue;
            }
            if(lireligne(dernierCoupX+i, dernierCoupY+j, i, j, joueurDernierCoup) +
               lireligne(dernierCoupX-i, dernierCoupY-j, -1*i, -1*j, joueurDernierCoup)  >=4){
                //VICTOIRE
                cout<<"joueur "<<joueurDernierCoup<<" a gagné la partie"<<endl;
                joueurVictorieux=joueurDernierCoup;
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
                //ON MANGE
                if(plateau[dernierCoupX+3*i][dernierCoupY+3*j]==joueurDernierCoup){
                    cout<<"mangé!"<<endl;
                    plateau[dernierCoupX+i][dernierCoupY+j]=0;
                    plateau[dernierCoupX+2*i][dernierCoupY+2*j]=0;
                    if(joueurDernierCoup==1){
                        p1+=2;
                    } else {
                        p2+=2;
                    }
                    if(p1==10){
                        cout<<"JOUEUR 1 A GAGNE avec 10 prisonniers"<<endl;
                        joueurVictorieux=1;
                    }
                    if(p2==10){
                        cout<<"JOUEUR 2 A GAGNE avec 10 prisonniers"<<endl;
                        joueurVictorieux=2;
                    }
                }
            }
        }
    }
    if(joueurVictorieux!=0){
        cout<<"joueur "<<joueurVictorieux<<" a gagné"<<endl;
    }
}


    //ACCESSEURS :

    int Jeu::getplateau(int x, int y){
        return plateau[x][y];
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
