
#include "joueurhumainconsole.h"

#include <iostream>

using namespace std;

void joueurHumainConsole::getCoup(Coup *coup)
{
    coup->numeroJoueur = getNumero();
		    
		cout<<"coup joueur 1 :" << endl;

    cout<<"            y :" << endl;
    cin>>coup->y;

    cout<<"            x :" << endl;
    cin>>coup->x;
}
