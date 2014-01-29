#ifndef JOUEURHUMAIN_H
#define JOUEURHUMAIN_H

#include "joueur.h"

class joueurHumainConsole : public Joueur
{
public:
    void getCoup(Coup *coup);
};

#endif // JOUEURHUMAIN_H
