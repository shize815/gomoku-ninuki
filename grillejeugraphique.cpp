#include "grillejeugraphique.h"

#include <QObject>

GrilleJeuGraphique::GrilleJeuGraphique(int largeur, int hauteur, QWidget *parent) :
    m_widgetGrilleJeu(largeur, hauteur, parent)
{
    QObject::connect(&m_widgetGrilleJeu, SIGNAL(sigPionClique(int,int) ), this, SLOT(slotPionClique(int,int) ) );
}

void GrilleJeuGraphique::affiche(std::vector < std::vector <int> > &plateau, int joueurVictorieux)
{
    m_widgetGrilleJeu.affiche(plateau);

}

WidgetGrilleJeu *GrilleJeuGraphique::getWidgetGrilleJeu()
{
    return &m_widgetGrilleJeu;
}
