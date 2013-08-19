#ifndef JEU_H
#define JEU_H
#include <vector>
#include <iostream>

struct coup{
    int x;
    int y;
};

using namespace std;

class jeu
{
    public:
        jeu();
        virtual ~jeu();
        void affiche(); //Affiche le palteau dans le terminal.
        void joue(int coup1, int coup2); //Fait jouer le coup au joueur 1
        void joue2(int coup1, int coup2); //Fait jouer le coup au joueur 2

        bool fin(); //renvoi vrai si la partie est fini.
        void regles(); //Applique les règles du jeu.
        int oppose(int couleur); //retourne la couleur inverse à la couleur entrée
        int lireligne(int x, int y, int d1, int d2, int couleur); //renvoi le nombre de pions de la couleur donné aligné dans la direction (d1,d2) een partant de la case (x,y)



        //ACCESSEURS :
        int getplateau(int x, int y);
        int getcx1();
        int getcy1();

        int getcx2();
        int getcy2();

        int getp1();
        int getp2();

        int getcc();



    protected:
    private:
        vector < vector <int> > plateau;

        //Dernier coup
        int cx;
        int cy;


        //Dernier coup J1
        int cx1;
        int cy1;

        //Dernier coup J2
        int cx2;
        int cy2;
        //TODO : A remplacer par une liste des coups joués (et adapter les accesseurs en conséquent)


        //Numero du joueur ayant fait le dernier coup
        int cc;

        int p1; //prisonniers du j1
        int p2;
        int v; //0 si la partie est en cours, sinon le numero de vainceur.
};

#endif // JEU_H
