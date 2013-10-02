#ifndef JEU_H
#define JEU_H
#include <vector>
#include <iostream>

struct Coup{
    int x;
    int y;
    int joueur;
};

enum Resultat {
    SUCCES,
    INVALIDE,
};


//Jeu contient tout ce qui a attrait au jeu (la résolution des prises, la détection d'un gagnant...)
//La classe conserve toutes les informations liés au plateau.

class Jeu
{
    public:
        Jeu();
        virtual ~Jeu();
        void affiche(); //Affiche le plateau dans le terminal.
        Resultat jouerCoup(Coup coup);

        bool fin(); //renvoie vrai si la partie est finie.

        int getp1();
        int getp2();

        //ACCESSEURS :
        int getplateau(int x, int y);
        std::vector<Coup> &getcoupsJoues();

    protected:
    private:
        void regles(Coup dernierCoup); //Applique les règles du jeu.
        int oppose(int couleur); //retourne la couleur inverse à la couleur entrée

        //renvoie le nombre de pions de la couleur donné aligné dans la direction (d1,d2) een partant de la case (x,y)
        int lireligne(int x, int y, int d1, int d2, int couleur);

        std::vector<Coup> coupsJoues;



        std::vector < std::vector <int> > plateau;


        //Numero du joueur ayant fait le dernier coup
        int joueurDernierCoup;

        int p1; //prisonniers du j1
        int p2;
        int v; //0 si la partie est en cours, sinon le numero de vainqueur.
};

#endif // JEU_H
