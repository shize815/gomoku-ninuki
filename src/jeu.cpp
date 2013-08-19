#include "../include/jeu.h"

#include <stdlib.h>

jeu::jeu()
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
    //ctor
}

jeu::~jeu()
{
    //dtor
}


void jeu::affiche(){
    cout<<"   0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15"<<endl;
    for(int i=0; i<15; i++){
        cout<<i<<" ";
        if(i<10){
        cout<<" ";
        }
        for(int j=0; j<15; j++){

            if(plateau[i][j]==0){
                cout<<".  ";
            }
            if(plateau[i][j]==1){
                cout<<"O  ";
            }
            if(plateau[i][j]==2){
                cout<<"X  ";
            }
        }
        cout<<endl;
    }
    if(v!=0){
        cout<<"joueur "<<v<<" a gagné"<<endl;
    }
}


void jeu::joue(int coup1, int coup2){ //Le joueur 1.
    plateau[coup1][coup2]=1;
    cx=coup1;
    cy=coup2;
    cx1=coup1;
    cy1=coup2;
    cc=1;
}

void jeu::joue2(int coup1, int coup2){ //Le joueur 1.
    plateau[coup1][coup2]=2;
    cx=coup1;
    cy=coup2;

    cx2=coup1;
    cy2=coup2;
    cc=2;
}


bool jeu::fin(){
    if(v==0){
        return false;
    } else {
        return true;
    }

}


int jeu::lireligne(int x, int y, int d1, int d2, int couleur){ //renvoi le nombre de pions de la couleur donné aligné dans la direction (d1,d2) een partant de la case (x,y)
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

int jeu::oppose(int couleur){
    if(couleur==2){
        return 1;
    }
    if(couleur==1){
        return 2;
    }

    return 0;


}

void jeu::regles(){
    //ligne
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i!=0 || j!=0){
                if(lireligne(cx+i,cy+j, i, j, cc) +lireligne(cx-i,cy-j, -1*i, -1*j, cc)  >=4){
                    //VICTOIRE
                    cout<<"joueur "<<cc<<"a gagné la partie"<<endl;
                    v=cc;
                }
            }
        }
    }


    //mange
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i!=0 || j!=0){
                //cout<<"nb l : "<<i<<j<<" : "<<lireligne(cx+i,cy+j, i, j, oppose(cc))<<endl;
                if(lireligne(cx+i,cy+j, i, j, oppose(cc))==2){
                    //ON MANGE
                    if(plateau[cx+3*i][cy+3*j]==cc){
                        cout<<"mangé!"<<endl;
                        plateau[cx+i][cy+j]=0;
                        plateau[cx+2*i][cy+2*j]=0;
                        if(cc==1){
                            p1+=2;
                        } else {
                            p2+=2;
                        }
                        if(p1==10){
                            cout<<"JOUEUR 1 A GAGNE avec 10 prisonniers"<<endl;
                            v=1;                        }
                        if(p2==10){
                            cout<<"JOUEUR 2 A GAGNE avec 10 prisonniers"<<endl;
                            v=2;
                        }
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

    int jeu::getplateau(int x, int y){
        return plateau[x][y];
    }

    int jeu::getcx1(){
        return cx1;
    }
    int jeu::getcy1(){
        return cy1;
    }

     int jeu::getcx2(){
        return cx2;
    }
    int jeu::getcy2(){
        return cy2;
    }

    int jeu::getp1(){
        return p1;
    }
    int jeu::getp2(){
        return p2;
    }

    int jeu::getcc(){
        return cc;
    }
