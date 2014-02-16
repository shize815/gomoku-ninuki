
#include "joueurIArandom.h"

#include <time.h>

using namespace std;

JoueurIaRandom::JoueurIaRandom()
{
    /* génère une "seed" pour que la fonction rand ne renvoye pas
        les mêmes suites de valeurs à chaque fois que le programme est lancé */
    srand(time(NULL));
}

Coup JoueurIaRandom::coupRand()
{
    Coup coup;
    coup.couleur=m_couleurPion;
    if (m_jeu->getcoupsJoues().size() == 0) {
        coup.x = 1;
        coup.y = 1;
        coup.couleur = m_couleurPion;
        return coup;
    }

    int cx=m_jeu->getcoupsJoues().back().x;
    int cy=m_jeu->getcoupsJoues().back().y;

    do{
        cx+=rand() % 3 - 1;
        cy+=rand() % 3 - 1;
        if(cx<0){
            cx=0;
        }
        if(cx>m_jeu->LARGEUR_PLATEAU - 1){
            cx=m_jeu->LARGEUR_PLATEAU - 1;
        }
        if(cy<0){
            cy=0;
        }
        if(cy>m_jeu->HAUTEUR_PLATEAU - 1){
            cy=m_jeu->HAUTEUR_PLATEAU - 1;
        }
    }while(m_jeu->getplateau(cx,cy)!=CouleurPion::aucuneCouleur);

    coup.x=cx;
    coup.y=cy;
    coup.couleur = m_couleurPion;
    return coup;
}


Coup JoueurIaRandom::getCoup()
{
    Coup coup = coupRand();
    
    cout << "l'IA joue x " << coup.x << ",y " << coup.y << " (joueur" << coup.couleur << ")" << endl;
    return coup;
}

