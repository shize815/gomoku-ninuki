#ifndef IA_H
#define IA_H
#include "./jeu.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


class IA
{
    public:
        IA();
        virtual ~IA();
        void repond(); //renvoi un coup donné par l'IA.
        void setjeu(Jeu * jeu);
    protected:
    private:
        bool coupRand(Coup * c); //joue coup aléatoire proche du dernier coup joué
        bool coupIntelligent(Coup * c);
        Jeu * jeu;
};

#endif // IA_H
