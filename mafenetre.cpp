#include "mafenetre.h"

MaFenetre::MaFenetre(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(300, 200);

    //automatiquement supprimé par Qt, pas besoin delete
    //m_bouton = new QPushButton("Pimp mon bouton!", this);

    //m_bouton->setFont(QFont("Comic Sans MS", 14) );
    //m_bouton->setCursor(Qt::PointingHandCursor);
    //m_bouton->move(100, 100);

    //QObject::connect(m_bouton, SIGNAL(clicked() ), qApp, SLOT(quit() ) );

    //m_lcd = new QLCDNumber(this);
    //m_lcd->setSegmentStyle(QLCDNumber::Flat);
    //m_lcd->move(50, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(50, 60, 150, 20);
    m_slider->setRange(250, 600);

    m_slider2 = new QSlider(Qt::Vertical, this);
    m_slider2->setGeometry(220, 20, 20, 150);
    m_slider2->setRange(200, 600);
    //m_progressBar = new QProgressBar(this);
    //m_progressBar->setGeometry(50, 30, 100, 20);

    //connect(m_slider, SIGNAL(valueChanged(int)), m_progressBar, SLOT(setValue(int)) );
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)) );
    QObject::connect(m_slider2, SIGNAL(valueChanged(int)), this, SLOT(changerHauteur(int)) );
}

void MaFenetre::changerLargeur(int largeur)
{
    setFixedSize(largeur, this->height());
}


void MaFenetre::changerHauteur(int hauteur)
{
    setFixedSize(this->width(), 800 - hauteur);
}
