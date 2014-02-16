
#include "fenetreprincipale.h"

#include "joueurhumaingui.h"
#include "joueurIArandom.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QWidget(parent),
    m_grille(Jeu::LARGEUR_PLATEAU, Jeu::HAUTEUR_PLATEAU, this),
    m_boutonNouveauJeu("Nouveau Jeu", this),
    m_choixTypeJoueur1("Joueur 1"),
    m_choixTypeJoueur2("Joueur 2")
{
    QObject::connect(&m_boutonNouveauJeu, SIGNAL(clicked()), this, SLOT(boutonNouveauJeuClique()) );

    int y = 0;
    layoutPrincipal.addWidget(m_grille.getWidgetGrilleJeu(), y++, 0, 1, 2);
    layoutPrincipal.addWidget(&m_choixTypeJoueur1, y, 0);
    layoutPrincipal.addWidget(&m_choixTypeJoueur2, y++, 1);

    layoutPrincipal.addWidget(&m_boutonNouveauJeu, y++, 0);
    this->setLayout(&layoutPrincipal);
}


void FenetrePrincipale::boutonNouveauJeuClique()
{
    m_choixTypeJoueur1.initTypeJoueur(m_joueur1);
    m_choixTypeJoueur2.initTypeJoueur(m_joueur2);

    m_jeu.reset(new Jeu(m_grille, *m_joueur1, *m_joueur2) );
    m_jeu->jouePartie();
}
