#ifndef IA_H
#define IA_H
#include "jeu.h"
#include "joueur.h"

#include <vector>
#include <iostream>
#include <stdlib.h>


class joueurIArandom : public Joueur
{
    public:
        joueurIArandom();
        virtual ~joueurIArandom() = default;
        void getCoup(Coup *coup); //renvoi un coup donné par l'IA.


    protected:
    private:
        bool coupRand(Coup * coup); //joue coup aléatoire proche du dernier coup joué
};

#endif // IA_H