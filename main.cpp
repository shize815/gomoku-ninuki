#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>

#include <memory>
#include <vector>
#include <iostream>

#include "jeu.h"
#include "fenetreprincipale.h"
#include "grillejeugraphique.h"
#include "grillejeuconsole.h"
#include "joueur.h"
#include "joueurhumainconsole.h"
#include "joueurhumaingui.h"
#include "joueurIArandom.h"

using namespace std;



//Le programme doit être recompilé SANS l'option "Run in Terminal" dans QtCreator->Projects->Run
//Sinon le programme GUI ne marche pas.
int mainGui(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenetrePrincipale *fenetre = new FenetrePrincipale();



    return app.exec();
}

//Le programme doit être recompilé AVEC l'option "Run in Terminal" dans QtCreator->Projects->Run
//Sinon le programme console ne marche pas.
int mainConsole()
{
    int nombreJoueurs = 1;
    cout << "Nombre de joueurs humains (doit être compris entre 0 et 2):" << endl;

    cin>>nombreJoueurs; /* TODO: sécuriser les saisies, au cas où quelqu'un tape des lettres par exemple */
    GrilleJeuConsole grille(Jeu::LARGEUR_PLATEAU, Jeu::HAUTEUR_PLATEAU);
    switch(nombreJoueurs) {
    case 0: {
        JoueurIaRandom joueur1;
        JoueurIaRandom joueur2;
        Jeu jeu(grille, joueur1, joueur2);
        jeu.jouePartie();
        break;
    }
    case 1: {
        JoueurHumainConsole joueur1;
        JoueurIaRandom joueur2;
        Jeu jeu(grille, joueur1, joueur2);
        jeu.jouePartie();
        break;
    }
    case 2: {
        JoueurHumainConsole joueur1;
        JoueurHumainConsole joueur2;
        Jeu jeu(grille, joueur1, joueur2);
        jeu.jouePartie();
        break;
    }
    default:
        cout << "nombre de joueurs invalide!" << endl;
        break;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    //Pour lancer le jeu en mode console, le programme doit être recompilé avec ou sans l'option "run in terminal" dans QtCreator.

    mainGui(argc, argv);
    //mainConsole();

    return 0;
}
