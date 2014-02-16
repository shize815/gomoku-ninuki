
#include "joueurhumainconsole.h"

#include <iostream>

using namespace std;

Coup JoueurHumainConsole::getCoup()
{
    Coup coup;
    coup.couleur = m_couleurPion;
		    
    cout<<"coup joueur :" << m_couleurPion << endl;

    cout<<"            y :" << endl;
    cin>>coup.y;

    cout<<"            x :" << endl;
    cin>>coup.x;

    return coup;
}
