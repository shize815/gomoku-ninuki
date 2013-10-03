#include "../include/IA.h"

#include <time.h>

using namespace std;

//ctor
IA::IA()
{
    /* génère une "seed" pour que la fonction rand ne renvoye pas
        les mêmes suites de valeurs à chaque fois que le programme est lancé */
    srand(time(NULL));
}

void IA::setjeu(Jeu * jeu){
    this->jeu = jeu;
}

//dtor
IA::~IA()
{

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

bool IA::coupRand(Coup * coup){
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


void IA::repond(){

    Coup reponse;
    reponse.joueur=this->joueur;
    if(coupIntelligent(&reponse)){

    } else {
        coupRand(&reponse);
    }
    cout << "l'IA joue x " << reponse.x << ",y " << reponse.y << " (joueur" << reponse.joueur << ")" << endl;
    if (jeu->jouerCoup(reponse) != SUCCES) {
        cerr << "l'IA a essayé de jouer un coup invalide!" << endl;
    }
}

void IA::setJoueur(int joueur)
{
    if (joueur == 1 || joueur == 2) {
        this->joueur = joueur;
    } else {
        cerr << "IA::setJoueur, joueur invalide!" << endl;
    }
}

int IA::getJoueur()
{
    return joueur;
}
