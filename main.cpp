#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <iostream>

#include "mafenetre.h"
#include "jeu.h"
#include "joueur.h"
#include "joueurhumainconsole.h"
#include "joueurIA.h"

using namespace std;

int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);

//    QWidget fenetre;

//    QLineEdit *nom = new QLineEdit;
//    QLineEdit *prenom = new QLineEdit;
//    QLineEdit *age = new QLineEdit;

//    QFormLayout *layout = new QFormLayout;
//    layout->addRow("votre &nom", nom);
//    layout->addRow("voter &prenom", prenom);
//    layout->addRow("votre &age", age);

//    fenetre.setLayout(layout);
//    fenetre.show();

    //return app.exec();

    int nombreJoueurs = 0;
    cout << "Nombre de joueurs humains (doit être compris entre 0 et 2):" << endl;

    cin>>nombreJoueurs; /* TODO: sécuriser les saisies, au cas où quelqu'un tape des lettres par exemple */
    Jeu jeu;
    switch(nombreJoueurs) {
    case 0: {
        joueurIA joueur1;
        joueurIA joueur2;
        jeu.jouePartie(joueur1, joueur2);
        break;
    }
    case 1: {
        joueurHumainConsole joueur1;
        joueurIA joueur2;
        jeu.jouePartie(joueur1, joueur2);
        break;
    }
    case 2: {
        joueurHumainConsole joueur1;
        joueurHumainConsole joueur2;
        jeu.jouePartie(joueur1, joueur2);
        break;
    }
    default:
        cout << "nombre de joueurs invalide!" << endl;
        break;
    }
}
