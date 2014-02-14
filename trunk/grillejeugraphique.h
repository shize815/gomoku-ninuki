#ifndef GRILLEJEUGRAPHIQUE_H
#define GRILLEJEUGRAPHIQUE_H

#include "grillejeu.h"
#include "widgetgrillejeu.h"


class GrilleJeuGraphique : public GrilleJeu
{
    Q_OBJECT
public:
    GrilleJeuGraphique(int largeur, int hauteur, QWidget *parent = 0);
    void affiche(std::vector < std::vector <int> > &plateau, int joueurVictorieux);
    WidgetGrilleJeu *getWidgetGrilleJeu();

private:
    WidgetGrilleJeu m_widgetGrilleJeu;
};

#endif // GRILLEJEUGRAPHIQUE_H
