#ifndef JOUEUR_H
#define JOUEUR_H

#include "coup.h"

class Jeu;

// Classe abstraite dont hérite IAs et joueurs humains
class Joueur
{
    public:
        Joueur() {}
        virtual ~Joueur() {}

        virtual void getCoup(Coup *coup) = 0; //renvoi un coup

        void setNumero(int numero); //configure le numéro du joueur incarné par le joueur (1 ou 2)
        int getNumero() { return this->numero; }

        void setjeu(Jeu * jeu) { this->jeu = jeu; }

    protected:
        Jeu * jeu;
        int numero;
};

#endif // JOUEUR_H
