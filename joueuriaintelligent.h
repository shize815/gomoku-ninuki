#ifndef JOUEURIAINTELLIGENT_H
#define JOUEURIAINTELLIGENT_H

#include "joueur.h"

class JoueurIaIntelligent : public Joueur
{
    Coup getCoup() override;
public:
    JoueurIaIntelligent();
};

#endif // JOUEURIAINTELLIGENT_H
