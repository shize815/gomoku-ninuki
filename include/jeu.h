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
        void affiche();
        void joue(int coup1, int coup2);
        void joue2(int coup1, int coup2);
        void repond();
        bool fin();
        void regles();
        int oppose(int couleur);
        //Dernier coup J1
        int cx1;
        int cy1;

        //Dernier coup J2
        int cx2;
        int cy2;

        //Numero du joueur ayant fait le dernier coup
        int cc;

        int p1; //prisonniers du j1
        int p2;
        int v;
        int lireligne(int x, int y, int d1, int d2, int couleur);
    protected:
    private:
    vector < vector <int> > plateau;
};

#endif // JEU_H
