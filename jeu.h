#ifndef JEU_H
#define JEU_H

#include <vector>
#include <iostream>
#include <QObject>

#include "coup.h"
#include "joueur.h"
#include "grillejeu.h"

enum Resultat {
    SUCCES,
    INVALIDE,
};


//Jeu contient tout ce qui a attrait au jeu (la résolution des prises, la détection d'un gagnant...)
//La classe conserve toutes les informations liées au plateau.
class Jeu : public QObject
{
    Q_OBJECT
    public:
        static const int HAUTEUR_PLATEAU = 15;
        static const int LARGEUR_PLATEAU = 15;

        Jeu(GrilleJeu &grilleJeu, Joueur &joueur1, Joueur &joueur2);
        ~Jeu() = default;






        //ACCESSEURS :
        int getp1();
        int getp2();
        int getplateau(int x, int y);
        std::vector<Coup> &getcoupsJoues();

    signals:
        void joueur1PionClique(Coup coupClique);
        void joueur2PionClique(Coup coupClique);

    public slots:
        //détermine à quel joueur c'est le tour de jouer et envoye un signal avec les coordonnées du pion cliqué
        //Ne sert que pour l'interface graphique (pas pour le mode console)
        void slotPionClique(int xNumero, int yNumero);
        void jouePartie(); //joue une partie

    private:
        int oppose(int couleur); //retourne la couleur inverse à la couleur entrée
        Resultat jouerCoup(Coup coup);
        void regles(); //Applique les règles du jeu.
        bool fin(); //renvoie vrai si la partie est finie.

        //renvoie le nombre de pions de la couleur donné aligné dans la direction (d1,d2) en partant de la case (x,y)
        int lireligne(int px, int py, int dx, int dy, int couleur);
        void getCoupEtJoue(Joueur &joueur);
        std::vector<Coup> coupsJoues;

        //contient la position des pions sur le plateau
        //chaque case contient soit 0(pas de pion), 1 (joueur1), ou 2 (joueur2)
        std::vector < std::vector <int> > m_plateau;

        //vue du jeu (graphique ou console)
        GrilleJeu &m_grilleJeu;

        Joueur &m_joueur1;
        Joueur &m_joueur2;

        int p1; //prisonniers du j1
        int p2;
        int m_joueurVictorieux; //0 si la partie est en cours, sinon le numero de vainqueur.
};

#endif // JEU_H
