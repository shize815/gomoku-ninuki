#include "../include/jeu.h"

#include <stdlib.h>
#define HAUTEUR_PLATEAU 15
#define LARGEUR_PLATEAU 15


Jeu::Jeu()
{
    plateau.resize(15);
    for(int it=0; it<15; it++){
        plateau[it].resize(15);
    }
    for(int i=0; i<15; i++){
        for(int j=0; j<15; j++){
            plateau[i][j]=0;
        }
    }
    v=0;
}

// destructor
Jeu::~Jeu()
{

}


void Jeu::affiche(){
    cout<<"   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15"<<endl;

    for(int y=0; y<HAUTEUR_PLATEAU; y++){
        cout<<y<<" ";
        if(y<10){
            cout<<" ";
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
    if(v!=0){
        cout<<"joueur "<<v<<" a gagné"<<endl;
    }
}

Resultat Jeu::coupJoueur1(Coup coup){
    if (coup.x > LARGEUR_PLATEAU || coup.y > HAUTEUR_PLATEAU) {
        return INVALIDE;
    }
    if (coup.x < 0 || coup.y < 0) {
        return INVALIDE;
    }
    if (plateau[coup.x][coup.y] != 0) {
        return INVALIDE;
    }

    plateau[coup.x][coup.y]=1;
    dernierCoupX=coup.x;
    dernierCoupY=coup.y;
    cx1=coup.x;
    cy1=coup.y;
    joueurDernierCoup=1;
    regles();
    return SUCCES;
}

void Jeu::coupJoueur2(Coup coup){
    plateau[coup.x][coup.y]=2;
    dernierCoupX=coup.x;
    dernierCoupY=coup.y;

    cx2=coup.x;
    cy2=coup.y;
    joueurDernierCoup=2;
    regles();
}


bool Jeu::fin(){
    if(v==0){
        return false;
    } else {
        return true;
    }

}

// renvoye le nombre de pions de la couleur donnée alignés dans la direction (d1,d2) en partant de la case (x,y)
int Jeu::lireligne(int x, int y, int d1, int d2, int couleur){
    int cpt=0;
    int px=x;
    int py=y;
    cout<<px<<" - "<<py<<" ( "<<couleur<<" ) : "<<plateau[px][py]<<endl;
    while(plateau[px][py]==couleur){
        cpt++;
        px+=d1;
        py+=d2;
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
    // détermine si 5 pierres sont alignées
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i==0 && j==0){
                continue;
            }
            if(lireligne(dernierCoupX+i,
                         dernierCoupY+j,
                          i,
                          j,
                          joueurDernierCoup) + lireligne(dernierCoupX-i,dernierCoupY-j, -1*i, -1*j, joueurDernierCoup)  >=4){
                //VICTOIRE
                cout<<"joueur "<<joueurDernierCoup<<"a gagné la partie"<<endl;
                v=joueurDernierCoup;
            }
        }
    }


    //mange pions si nécessaire
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i!=0 || j!=0){
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
                        v=1;
                    }
                    if(p2==10){
                        cout<<"JOUEUR 2 A GAGNE avec 10 prisonniers"<<endl;
                        v=2;
                    }
                }
            }
        }
    }
    if(v!=0){
        cout<<"joueur "<<v<<" a gagné"<<endl;
    }
}


    //ACCESSEURS :

    int Jeu::getplateau(int x, int y){
        return plateau[x][y];
    }


    int Jeu::getdernierCoupX(){
        return dernierCoupX;
    }
    int Jeu::getdernierCoupY(){
        return dernierCoupY;
    }

    int Jeu::getcx1(){
        return cx1;
    }
    int Jeu::getcy1(){
        return cy1;
    }

     int Jeu::getcx2(){
        return cx2;
    }
    int Jeu::getcy2(){
        return cy2;
    }

    int Jeu::getp1(){
        return p1;
    }
    int Jeu::getp2(){
        return p2;
    }

    int Jeu::getjoueurDernierCoup(){
        return joueurDernierCoup;
    }
