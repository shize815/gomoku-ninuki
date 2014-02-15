
#include "fenetreprincipale.h"

#include "joueurhumaingui.h"
#include "joueurIArandom.h"

FenetrePrincipale::FenetrePrincipale(QWidget *parent) :
    QWidget(parent)
{
    grille = new GrilleJeuGraphique(Jeu::LARGEUR_PLATEAU, Jeu::HAUTEUR_PLATEAU, this);

    boutonNouveauJeu = new QPushButton("Nouveau Jeu", this);

    QObject::connect(boutonNouveauJeu, SIGNAL(clicked()), this, SLOT(boutonNouveauJeuClique()) );
    m_choixTypeJoueur1 = new ChoixTypeJoueur("Joueur 1");
    m_choixTypeJoueur2 = new ChoixTypeJoueur("Joueur 1");

    QGridLayout *layoutPrincipal = new QGridLayout();
    int y = 0;
    layoutPrincipal->addWidget(grille->getWidgetGrilleJeu(), y++, 0, 1, 2);
    layoutPrincipal->addWidget(m_choixTypeJoueur1, y, 0);
    layoutPrincipal->addWidget(m_choixTypeJoueur2, y++, 1);

    layoutPrincipal->addWidget(boutonNouveauJeu, y++, 0);
    this->setLayout(layoutPrincipal);

    this->show();
}


void FenetrePrincipale::boutonNouveauJeuClique()
{
    m_choixTypeJoueur1->initTypeJoueur(joueur1);
    m_choixTypeJoueur2->initTypeJoueur(joueur2);

    jeu.reset(new Jeu(*grille, *joueur1, *joueur2) );
    jeu->jouePartie();
}
