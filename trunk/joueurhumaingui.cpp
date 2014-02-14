#include "joueurhumaingui.h"

#include <iostream>
#include <QEventLoop>
#include <QCoreApplication>

using namespace::std;


Coup JoueurHumainGui::getCoup()
{
    std::cout << "Attend que joueur humain clique sur un pion" << std::endl;

    QEventLoop loop;
    QObject::connect(this, SIGNAL(sigCoupClique(Coup)), &loop, SLOT(quit()));

    // Attend que le joueur humain clique sur un pion
    loop.exec();

    if (m_coupValide == false) {
        //le joueur a cliqué sur la croix, ce qui a interrompu notre eventLoop.
        cout << "Jeu quitté. " << endl;
        exit(EXIT_SUCCESS);
    }
    cout << "Joueur " << m_numeroJoueur <<
            " joue x " << m_coupClique.x <<
            ",y " << m_coupClique.y << " (joueur humain)" << endl;
    m_coupValide = false;
    return m_coupClique;
}

void JoueurHumainGui::slotCoupClique(Coup coupClique)
{
    m_coupClique = coupClique;
    m_coupValide = true;
    emit sigCoupClique(coupClique);
}
