#ifndef JOUEURHUMAIN_H
#define JOUEURHUMAIN_H

#include "joueur.h"

class JoueurHumainConsole : public Joueur
{
public:
    Coup getCoup();
};

#endif // JOUEURHUMAIN_H
