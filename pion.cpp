#include "pion.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPen>



Pion::Pion(unsigned int xNumero,
           unsigned int yNumero,
           qreal x,
           qreal y,
           qreal width,
           qreal height,
           QGraphicsItem * parent) :
    QGraphicsEllipseItem(x, y, width, height, parent),
    m_xNumero(xNumero),
    m_yNumero(yNumero)
{
    QPen blackPen(Qt::black);
    QBrush blackBrush(Qt::black);
    this->setBrush(blackBrush);
    this->setPen(blackPen);
}

void Pion::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit sigPionClique(m_yNumero, m_xNumero);
}


