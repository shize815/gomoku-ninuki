#ifndef JOUEURIAINTELLIGENT_H
#define JOUEURIAINTELLIGENT_H

#include "joueur.h"

class JoueurIaIntelligent : public Joueur
{
    void getCoup(Coup *coup);
public:
    JoueurIaIntelligent();
};

#endif // JOUEURIAINTELLIGENT_H
