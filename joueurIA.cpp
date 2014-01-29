
#include "joueurIA.h"

#include <time.h>

using namespace std;

joueurIA::joueurIA()
{
    /* génère une "seed" pour que la fonction rand ne renvoye pas
        les mêmes suites de valeurs à chaque fois que le programme est lancé */
    srand(time(NULL));
}

joueurIA::~joueurIA()
{

}

bool joueurIA::coupIntelligent(Coup * coup){ //TODO!
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

bool joueurIA::coupRand(Coup * coup)
{
    int cx=jeu->getcoupsJoues().back().x;
    int cy=jeu->getcoupsJoues().back().y;

    do{
        cx+=rand() % 3 - 1;
        cy+=rand() % 3 - 1;
        if(cx<0){
            cx=0;
        }
        if(cx>LARGEUR_PLATEAU - 1){
            cx=LARGEUR_PLATEAU - 1;
        }
        if(cy<0){
            cy=0;
        }
        if(cy>HAUTEUR_PLATEAU - 1){
            cy=HAUTEUR_PLATEAU - 1;
        }
    }while(jeu->getplateau(cx,cy)!=0);

    coup->x=cx;
    coup->y=cy;
    return true;
}


void joueurIA::getCoup(Coup *coup)
{
    coup->numeroJoueur=this->numero;
    if(coupIntelligent(coup)){

    } else {
        coupRand(coup);
    }
    cout << "l'IA joue x " << coup->x << ",y " << coup->y << " (joueur" << coup->numeroJoueur << ")" << endl;
}

