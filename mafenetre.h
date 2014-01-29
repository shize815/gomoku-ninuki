#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QApplication>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QPushButton>
#include <QWidget>

class MaFenetre : public QWidget
{
    Q_OBJECT
public:
    explicit MaFenetre(QWidget *parent = 0);
    
signals:
    
public slots:

    void changerLargeur(int largeur);
    void changerHauteur(int hauteur);

private:
    //QPushButton *m_bouton;
    //QLCDNumber *m_lcd;
    QSlider *m_slider;
    QSlider *m_slider2;
    //QProgressBar *m_progressBar;
};

#endif // MAFENETRE_H
