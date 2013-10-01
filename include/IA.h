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
        bool coupRand(Coup * c);
        bool coupIntelligent(Coup * c);
        void setjeu(Jeu * jt);
    protected:
    private:
        Jeu * j;
};

#endif // IA_H
