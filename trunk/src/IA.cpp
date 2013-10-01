#include "../include/IA.h"


IA::IA()
{
    //ctor
}

void IA::setjeu(Jeu * jt){
    j = jt;
}

IA::~IA()
{
    //dtor
}



bool IA::coupIntelligent(Coup * c){ //TODO!
    //Ordi a 4 pions alignés :
    /*
    for(int x=0; x<plateau.size(); x++){
        for(int y=0; y<plateau.size(); y++){
            if(plateau()){

            }
        }

    }
    */
    return false;

}


bool IA::coupRand(Coup * c){

    int c1= rand()%3-1+j->getcx1();
    int c2= rand()%3-1+j->getcy1();
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
    if(j->getplateau(c1,c2)==0){
       //plateau[c1][c2]=2;
    } else {
        while(j->getplateau(c1,c2)!=0){
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
    c->x=c1;
    c->y=c2;
    return true;

}


void IA::repond(){

    Coup reponse;
    if(coupIntelligent(&reponse)){

    } else {
        coupRand(&reponse);
    }
    j->coupJoueur2(reponse);
}
