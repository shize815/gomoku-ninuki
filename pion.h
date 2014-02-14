#ifndef PION_H
#define PION_H

#include <QGraphicsEllipseItem>
#include <QObject>

//#include "widgetgrillejeu.h"

//class WidgetGrilleJeu;

class Pion : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit Pion(unsigned int xNumero,
                  unsigned int yNumero,
                  qreal x, //coordonnée x du coin haut gauche en pixel
                  qreal y, //coordonnée y du coin haut gauche en pixel
                  qreal width,
                  qreal height,
                  QGraphicsItem * parent = 0 );
signals:
    void sigPionClique(int x, int y);

public slots:

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:

    unsigned int m_xNumero; //numero du pion dans la grille, axe horizontal en commencant par 0. (0,0) est en haut à gauche
    unsigned int m_yNumero; //numero du pion dans la grille, axe vertical en commencant par 0
    //WidgetGrilleJeu &m_widgetGrilleJeu;
};

#endif // PION_H
