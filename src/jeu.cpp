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


void jeu::joue(int coup1, int coup2){
    plateau[coup1][coup2]=1;
    cx=coup1;
    cy=coup2;
    cc=1;
}

void jeu::joue2(int coup1, int coup2){
    plateau[coup1][coup2]=2;
    cx=coup1;
    cy=coup2;
    cc=2;
}

bool coupIntelligent(coup * c){
    //Ordi a 4 pions alignés :
    for(int x=0; x<plateau.size(); x++){
        for(int y=0; y<plateau.size(); y++){
            if(plateau()){

            }
        }

    }


}


bool jeu::coupRand(coup * c){

    int c1= rand()%3-1+cx1;
    int c2= rand()%3-1+cy1;
    if(c1<0){
        c1=0;
    }
    if(c1>15){
        c1=15;
    }
    if(c2<0){
        c2=0;
    }
    if(c2>15){
        c2=15;
    }
    if(plateau[c1][c2]==0){
       //plateau[c1][c2]=2;
    } else {
        while(plateau[c1][c2]!=0){
            c1+=rand()%3-1;
            c2+=rand()%3-1;
            if(c1<0){
                c1=0;
            }
            if(c1>15){
                c1=15;
            }
            if(c2<0){
                c2=0;
            }
            if(c2>15){
                c2=15;
            }
        }
        //plateau[c1][c2]=2;
    }
    /*
    cx=c1;
    cy=c2;
    cc=2;
    */
    //coup retour;
    c.x=c1;
    c.y=c2;
    return true;

}


void jeu::repond(){

    coup reponse;
    if(coupIntelligent(&reponse)){
        cx = reponse.x;
        cy = reponse.y;
    } else {
        coupRand(&reponse);
        cx = reponse.x;
        cy = reponse.y;
    }
    plateau[c1][c2]=2;
    cx=c1;
    cy=c2;
    cc=2;
}


bool jeu::fin(){
    return false;

}


int jeu::lireligne(int x, int y, int d1, int d2, int couleur){
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
