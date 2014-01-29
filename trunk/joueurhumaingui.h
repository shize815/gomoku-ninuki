#ifndef JOUEURHUMAINGUI_H
#define JOUEURHUMAINGUI_H

#include "joueur.h"

//gui = Graphical User Interface (interface graphique)
class joueurHumainGui : public Joueur
{
public:
    joueurHumainGui();
    void getCoup(Coup *coup);
};

#endif // JOUEURHUMAINGUI_H
