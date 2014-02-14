#include "joueurhumaingui.h"

#include <iostream>
#include <QEventLoop>

using namespace::std;

void joueurHumainGui::getCoup(Coup *coup)
{

    std::cout << "starting to wait" << std::endl;


    QEventLoop loop;
    QObject::connect(this, SIGNAL(sigCoupClique(Coup)), &loop, SLOT(quit()));

    // Attend que le joueur humain clique sur un pion
    loop.exec();
    *coup = m_coupClique;
    cout << "Joueur " << m_numeroJoueur << " joue x " << coup->x << ",y " << coup->y << " (joueur humain)" << endl;
}

void joueurHumainGui::slotCoupClique(Coup coupClique)
{
    m_coupClique = coupClique;
    emit sigCoupClique(coupClique);
}
