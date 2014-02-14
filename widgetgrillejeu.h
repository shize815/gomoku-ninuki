#ifndef WidgetGrilleJeu_H
#define WidgetGrilleJeu_H

#include <vector>
#include <memory>

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsGridLayout>
#include <QtGui>

#include "jeu.h"
#include "pion.h"


class WidgetGrilleJeu : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGrilleJeu(int largeur, int hauteur, QWidget *parent = 0);
    void affiche(std::vector < std::vector <int> > &plateau);

signals:
    void sigPionClique(int xNumero, int yNumero);
public slots:
    void slotPionClique(int xNumero, int yNumero); // Les pions appellent cette function lorsqu'un joueur clique dessus.

private:
    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
    std::vector<std::vector<QGraphicsRectItem *> > m_carreaux;
    std::vector<std::vector<Pion *> > m_pions;

};

#endif // WidgetGrilleJeu_H
