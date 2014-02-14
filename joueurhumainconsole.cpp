
#include "joueurhumainconsole.h"

#include <iostream>

using namespace std;

Coup joueurHumainConsole::getCoup()
{
    Coup coup;
    coup.numeroJoueur = m_numeroJoueur;
		    
    cout<<"coup joueur :" << m_numeroJoueur << endl;

    cout<<"            y :" << endl;
    cin>>coup.y;

    cout<<"            x :" << endl;
    cin>>coup.x;

    return coup;
}
