#ifndef IA_H
#define IA_H
#include "jeu.h"
#include "joueur.h"

#include <vector>
#include <iostream>
#include <stdlib.h>


class JoueurIaRandom : public Joueur
{
    public:
        JoueurIaRandom();
        ~JoueurIaRandom() = default;
        Coup getCoup(); //renvoie un coup donné par l'IA.

    private:
        Coup coupRand(); //renvoie coup aléatoire proche du dernier coup joué
};

#endif // IA_H
