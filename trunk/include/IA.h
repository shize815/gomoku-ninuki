#ifndef IA_H
#define IA_H
#include "./jeu.h"
#include <vector>
#include <iostream>
#include <stdlib.h>


class IA
{
    public:
        IA();
        virtual ~IA();
        void repond(); //renvoi un coup donné par l'IA.
        void setjeu(Jeu * jeu);
        void setJoueur(int joueur); //configure le numéro du joueur incarné par l'IA (1 ou 2)
        int getJoueur();
    protected:
    private:
        int joueur;
        bool coupRand(Coup * c); //joue coup aléatoire proche du dernier coup joué
        bool coupIntelligent(Coup * c);
        Jeu * jeu;
};

#endif // IA_H
