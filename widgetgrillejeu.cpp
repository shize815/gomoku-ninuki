#include "widgetgrillejeu.h"

#include <vector>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtGui>
#include <QGraphicsGridLayout>
#include <QObject>

WidgetGrilleJeu::WidgetGrilleJeu(int largeur, int hauteur, QWidget *parent) :
    QWidget(parent)
{
    m_scene = new QGraphicsScene();
    m_view = new QGraphicsView(this);
    m_view->setScene(m_scene);


    QBrush whiteBrush(Qt::white);
    QBrush blackBrush(Qt::black);
    QBrush backgroundBrush(QColor(255, 153, 51, 200) );
    QPen blackpen(Qt::black);

    for (int x = 0; x < largeur+1; x++) {
        std::vector<QGraphicsRectItem *> colonne;
        std::vector<Pion *> colonnePions;
        for (int y = 0; y < hauteur+1; y++) {

            const int coteCarre = 50; //côté carré
            QGraphicsRectItem *carreau = m_scene->addRect(x*coteCarre, y*coteCarre, coteCarre, coteCarre, blackpen, backgroundBrush);
            carreau->setZValue(0);
            colonne.push_back(carreau);

            const int diametrePion = 30;
            Pion *pion = new Pion(x, y, coteCarre * x + coteCarre - (diametrePion / 2),
                                        coteCarre * y + coteCarre - (diametrePion / 2), diametrePion, diametrePion);
            //affiche un pion sur 2 en blanc en début de partie pour faire joli
            if ( (x + y) % 2 == 0)
                pion->setBrush(blackBrush);
            else
                pion->setBrush(whiteBrush);

            QObject::connect(pion, SIGNAL(sigPionClique(int, int)), this, SLOT(slotPionClique(int, int)));
            m_scene->addItem(pion);

            pion->setZValue(1);

            if (x == largeur || y == hauteur) {
                pion->setVisible(false);
            }
            colonnePions.push_back(pion);
        }
        m_carreaux.push_back(colonne);
        m_pions.push_back(colonnePions);
    }
    this->setFixedSize(800, 800);
}


void WidgetGrilleJeu::slotPionClique(int xNumero, int yNumero)
{
    emit sigPionClique(xNumero, yNumero);
}

void WidgetGrilleJeu::affiche(std::vector < std::vector <CouleurPion> > &plateau)
{
    QBrush whiteBrush(Qt::white);
    QBrush blackBrush(Qt::black);
    for (unsigned int x = 0; x < plateau.size(); x++) {
        for (unsigned int y = 0; y < plateau[x].size(); y++) {
            /* on utilise la méthode setOpacity pour rendre les pions visibles ou invisibles.
                Le problème en utilisant la méthode setVisible est que les pions non-visibles
                ne peuvent pas recevoir d'event "clic de souris", pareil si on utilise setOpacity(0,0).
                Avec setOpacity(0.01) le pion n'est pas visible mais attrape quand même les évènements de clics. */
            switch (plateau[y][x]) {
            case CouleurPion::aucuneCouleur:
                m_pions[x][y]->setOpacity(0.01);
                break;
            case CouleurPion::noir:
                m_pions[x][y]->setBrush(blackBrush);
                m_pions[x][y]->setOpacity(1.0);
                break;
            case CouleurPion::blanc:
                m_pions[x][y]->setBrush(whiteBrush);
                m_pions[x][y]->setOpacity(1.0);
                break;
            }
        }
    }
}
