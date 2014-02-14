#include "grillejeuconsole.h"

#include <iostream>

using namespace::std;

GrilleJeuConsole::GrilleJeuConsole(int largeur, int hauteur) :
    m_largeur(largeur), m_hauteur(hauteur)
{
}

void GrilleJeuConsole::affiche(std::vector < std::vector <int> > &plateau, int joueurVictorieux)
{
    //numï¿½ros des colonnes affichï¿½s en haut
    cout <<"   ";
    for (int x=0; x<m_largeur; x++){
        if (x<10){
            cout<<x<<"  ";
        } else{
            cout<<x<<" ";
        }
    }
    cout << endl;

    //reste du plateau
    for(int y=0; y<m_hauteur; y++){
        if(y<10){
            cout<<y<<"  ";
        } else {
            cout<<y<<" ";
        }

        for(int x=0; x<m_largeur; x++){

            if(plateau[x][y]==0){
                cout<<".  ";
            }
            else if(plateau[x][y]==1){
                cout<<"O  ";
            }
            else if(plateau[x][y]==2){
                cout<<"X  ";
            }
        }
        cout<<endl;
    }

    if(joueurVictorieux!=0){
        cout<<"joueur "<<joueurVictorieux<<" a gagnï¿½"<<endl;
    }
}
