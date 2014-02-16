#ifndef JOUEUR_H
#define JOUEUR_H

#include "coup.h"

#include <iostream>
#include <QObject>

class Jeu;

// Classe abstraite dont hérite IAs et joueurs humains
class Joueur : public QObject
{
    Q_OBJECT
    public:


        Joueur() = default;
        virtual ~Joueur() = default;

        virtual Coup getCoup() = 0; //renvoie un coup

        void setCouleur(CouleurPion couleur) //configure le numéro du joueur incarné par le joueur (1 ou 2)
        {
            if (couleur == CouleurPion::aucuneCouleur) {
                std::cerr << "couleur invalide!" << std::endl;
            }
            m_couleurPion = couleur;
        }

        CouleurPion getCouleur() { return m_couleurPion; }
        void setjeu(Jeu * jeu) { m_jeu = jeu; }

    public slots:
        //TODO: si possible trouver une meilleure abstraction,
        //ce slot est utilisé uniquement par joueurHumainConsole
        //pour détecter quand le joueur clique sur un pion
        virtual void slotCoupClique(Coup coupClique) {(void) coupClique;}

    protected:
        Jeu * m_jeu;
        CouleurPion m_couleurPion;
};

#endif // JOUEUR_H
