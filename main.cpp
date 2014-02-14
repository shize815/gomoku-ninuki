#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

#include <memory>
#include <vector>
#include <iostream>

#include "jeu.h"
#include "grillejeugraphique.h"
#include "joueur.h"
#include "joueurhumainconsole.h"
#include "joueurhumaingui.h"
#include "joueurIArandom.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *fenetre1 = new QWidget();

    QGridLayout *layout = new QGridLayout();
    GrilleJeuGraphique *grille = new GrilleJeuGraphique(15, 15, fenetre1);
    QPushButton *bouton = new QPushButton("Nouveau Jeu", fenetre1);
    layout->addWidget(grille->getWidgetGrilleJeu(), 0, 0);
    layout->addWidget(bouton, 1, 0);
    fenetre1->setLayout(layout);

    fenetre1->show();

    int nombreJoueurs = 1;
    //cout << "Nombre de joueurs humains (doit être compris entre 0 et 2):" << endl;

    //cin>>nombreJoueurs; /* TODO: sécuriser les saisies, au cas où quelqu'un tape des lettres par exemple */

    switch(nombreJoueurs) {
    case 0: {
        JoueurIaRandom joueur1;
        JoueurIaRandom joueur2;
        Jeu jeu(*grille, joueur1, joueur2);
        QObject::connect(bouton, SIGNAL(clicked()), &jeu, SLOT(jouePartie()) );
        return app.exec();
    }
    case 1: {
        JoueurHumainGui joueur1;
        JoueurIaRandom joueur2;
        Jeu jeu(*grille, joueur1, joueur2);
        QObject::connect(bouton, SIGNAL(clicked()), &jeu, SLOT(jouePartie()) );
        return app.exec();
    }
    case 2: {
        joueurHumainConsole joueur1;
        joueurHumainConsole joueur2;
        Jeu jeu(*grille, joueur1, joueur2);
        QObject::connect(bouton, SIGNAL(clicked()), &jeu, SLOT(jouePartie()) );
        return app.exec();
    }
    default:
        cout << "nombre de joueurs invalide!" << endl;
        break;
    }
    return 0;
}
