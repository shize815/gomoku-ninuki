#include "choixtypejoueur.h"

#include <QGridLayout>
#include <QLabel>

ChoixTypeJoueur::ChoixTypeJoueur(const QString & text, QWidget *parent) :
    QWidget(parent)
{
    QLabel *labelJoueur = new QLabel(text, this);
    joueurHumain = new QRadioButton("Humain", this);
    joueurHumain->setChecked(true);
    joueurIaRandom = new QRadioButton("IA (aleatoire)", this);

    QGridLayout *layoutChoixJoueur = new QGridLayout();
    int yChoixJoueur = 0;
    layoutChoixJoueur->addWidget(labelJoueur, yChoixJoueur++, 0);
    layoutChoixJoueur->addWidget(joueurHumain, yChoixJoueur++, 0);
    layoutChoixJoueur->addWidget(joueurIaRandom, yChoixJoueur++, 0);
    this->setLayout(layoutChoixJoueur);

}

void ChoixTypeJoueur::initTypeJoueur(std::unique_ptr<Joueur> &joueur)
{
    if (joueurHumain->isChecked()) {
        joueur.reset( new JoueurHumainGui() );
    }
    else if (joueurIaRandom->isChecked()) {
        joueur.reset( new JoueurIaRandom() );
    }
}
