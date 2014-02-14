#ifndef GRILLEJEU_H
#define GRILLEJEU_H

#include <vector>
#include <QObject>

//TODO si possible améliorer cette abstraction, le fait que GrilleJeu dérive de QObject
//ne sert à rien pour GrilleJeuConsole, mais est nécessaire pour GrilleJeuGraphique
//La classe Jeu doit utiliser cette interface, et du coup je suis obligé de définir les
//slots et signaux ici.

class GrilleJeu : public QObject
{
    Q_OBJECT
public:
    GrilleJeu() = default;
    virtual ~GrilleJeu() = default;

    virtual void affiche(std::vector < std::vector <int> > &plateau, int joueurVictorieux) = 0; //Affiche le plateau

signals:
    void sigPionClique(int xNumero, int yNumero);
public slots:
    void slotPionClique(int xNumero, int yNumero) { emit sigPionClique(xNumero, yNumero); }

};
#endif // GRILLEJEU_H
