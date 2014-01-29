
#include "joueur.h"

#include <iostream>

using namespace std;

void Joueur::setNumero(int numero)
{
    if (numero != 1 && numero != 2) {
        cerr << "Joueur::setNumero, numero invalide!" << endl;
    }
    this->numero = numero;
}
