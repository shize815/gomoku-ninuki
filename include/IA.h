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
        bool coupRand(coup * c);
        bool coupIntelligent(coup * c);
        void setjeu(jeu * jt);
    protected:
    private:
        jeu * j;
};

#endif // IA_H
