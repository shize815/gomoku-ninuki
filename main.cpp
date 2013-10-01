
#include "./include/jeu.h"
#include "./include/IA.h"
#include <cstring>

void joueurContreIA(){
    Coup coup;
    Jeu jeu;
    IA ia;
    ia.setjeu(&jeu);

    while(!jeu.fin()){
        jeu.affiche();
        cout<<"coup joueur 1 :" << endl;
        cout<<"            y :" << endl;
        cin>>coup.y;
        cout<<"            x :" << endl;
        cin>>coup.x;
        if (jeu.coupJoueur1(coup) != SUCCES){
            cout << "coup invalide" << endl;
            continue;
        }
        jeu.affiche();
        ia.repond();
    }
}

void joueurContreJoueur(){
    Coup coup;
    Jeu jeu;

    while(!jeu.fin()){
        jeu.affiche();
        cout<<"coup joueur 1 :"<<endl;
        cin>>coup.y;
        cin>>coup.x;
        jeu.coupJoueur1(coup);

        jeu.affiche();
        cout<<"coup joueur 2 :"<<endl;
        cin>>coup.y;
        cin>>coup.x;
        jeu.coupJoueur2(coup);
    }
}

int main(){
    int nombreJoueurs = 0;
    cout << "Entrez 1 pour jouer contre l'IA, 2 pour jouer contre un humain." << endl;

    cin>>nombreJoueurs; /* TODO: sécuriser les saisies, au cas où quelqu'un tape des lettres par exemple */
    if (nombreJoueurs == 1) {
        //"mode 1 joueur"
        joueurContreIA();
    } else if (nombreJoueurs == 2) {
        // "mode 2 joueurs"
        joueurContreJoueur();
    }

    return 0;
}
