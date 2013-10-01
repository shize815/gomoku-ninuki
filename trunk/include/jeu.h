#ifndef JEU_H
#define JEU_H
#include <vector>
#include <iostream>

struct Coup{
    int x;
    int y;
};

enum Resultat {
    SUCCES,
    INVALIDE,
};

using namespace std;

//Jeu contient tout ce qui a attrait au jeu (la résolution des prises, la détection d'un gagnant...)
//La classe conserve toutes les informations liés au plateau.

class Jeu
{
    public:
        Jeu();
        virtual ~Jeu();
        void affiche(); //Affiche le plateau dans le terminal.
        Resultat coupJoueur1(Coup coup); //Fait jouer le coup au joueur 1
        void coupJoueur2(Coup coup); //Fait jouer le coup au joueur 2

        bool fin(); //renvoie vrai si la partie est finie.
        void regles(); //Applique les règles du jeu.
        int oppose(int couleur); //retourne la couleur inverse à la couleur entrée

        //renvoie le nombre de pions de la couleur donné aligné dans la direction (d1,d2) een partant de la case (x,y)
        int lireligne(int x, int y, int d1, int d2, int couleur);



        //ACCESSEURS :
        int getplateau(int x, int y);


        int getdernierCoupX();
        int getdernierCoupY();

        int getcx1();
        int getcy1();

        int getcx2();
        int getcy2();


        int getp1();
        int getp2();

        int getjoueurDernierCoup();



    protected:
    private:
        vector < vector <int> > plateau;

        //Dernier coup
        int dernierCoupX;
        int dernierCoupY;


        //Dernier coup J1
        int cx1;
        int cy1;

        //Dernier coup J2
        int cx2;
        int cy2;
        //TODO : A remplacer par une liste des coups joués (et adapter les accesseurs en conséquent)


        //Numero du joueur ayant fait le dernier coup
        int joueurDernierCoup;

        int p1; //prisonniers du j1
        int p2;
        int v; //0 si la partie est en cours, sinon le numero de vainqueur.
};

#endif // JEU_H
