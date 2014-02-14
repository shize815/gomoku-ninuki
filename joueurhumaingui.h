#ifndef JOUEURHUMAINGUI_H
#define JOUEURHUMAINGUI_H

#include "joueur.h"

//gui = Graphical User Interface (interface graphique)
class joueurHumainGui : public Joueur
{
    Q_OBJECT
public:
    joueurHumainGui() = default;
    void getCoup(Coup *coup);

signals:
    void sigCoupClique(Coup coupClique);
public slots:
    void slotCoupClique(Coup coupClique);

private:
    //variable écrite par le slot pionCliqué et lue dans la fonction getCoup.
    Coup m_coupClique;
};

#endif // JOUEURHUMAINGUI_H
