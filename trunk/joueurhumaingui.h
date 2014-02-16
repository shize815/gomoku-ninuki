#ifndef JOUEURHUMAINGUI_H
#define JOUEURHUMAINGUI_H

#include "joueur.h"

//gui = Graphical User Interface (interface graphique)
class JoueurHumainGui : public Joueur
{
    Q_OBJECT
public:
    JoueurHumainGui() = default;
    Coup getCoup() override;

signals:
    void sigCoupClique(Coup coupClique);
public slots:
    void slotCoupClique(Coup coupClique);

private:
    //variable écrite par le slot pionCliqué et lue dans la fonction getCoup.
    Coup m_coupClique;
    bool m_coupValide;
};

#endif // JOUEURHUMAINGUI_H
