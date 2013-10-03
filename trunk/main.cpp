
#include "./include/jeu.h"
#include "./include/IA.h"
#include <cstring>

using namespace std;

void IAContreIA(){
    Coup coup = {
        .x = 0,
        .y = 0,
        .joueur = 1,
    };
    Jeu jeu;
    IA ia1;
    IA ia2;
    ia1.setjeu(&jeu);
    ia1.setJoueur(1);

    ia2.setjeu(&jeu);
    ia2.setJoueur(2);

    jeu.jouerCoup(coup); /* TODO pour l'instant on est obligé de jouer ce premier coup parce que l'IA
                            ne peut que réponse à un coup */
    while(!jeu.fin()){
        jeu.affiche();
        ia1.repond();

        jeu.affiche();
        ia2.repond();
    }
    /* affiche le plateau victorieux */
    jeu.affiche();
}

void joueurContreIA(){
    Coup coup = {
        .x = 0,
        .y = 0,
        .joueur = 1,
    };
    Jeu jeu;
    IA ia;
    ia.setjeu(&jeu);
    ia.setJoueur(2);

    while(!jeu.fin()){
        jeu.affiche();
        cout<<"coup joueur 1 :" << endl;
        cout<<"            y :" << endl;
        cin>>coup.y;
        cout<<"            x :" << endl;
        cin>>coup.x;
        if (jeu.jouerCoup(coup) != SUCCES){
            cerr << "coup invalide" << endl;
            continue; /* fait rejouer joueur 1 */
        }
        jeu.affiche();
        ia.repond();
    }
    /* affiche le plateau victorieux */
    jeu.affiche();
}

void joueurContreJoueur(){
    Coup coup = {
        .x = 0,
        .y = 0,
        .joueur = 1,
    };
    Jeu jeu;

    while(!jeu.fin()){
        jeu.affiche();
        cout<<"coup joueur " << coup.joueur << " :" <<endl;
        cout<<"            y :" << endl;
        cin>>coup.y;
        cout<<"            x :" << endl;
        cin>>coup.x;
        if (jeu.jouerCoup(coup) != SUCCES){
            //le joueur doit rejouer
            cerr << "coup invalide" << endl;
        } else {
            coup.joueur = jeu.oppose(coup.joueur);
        }
    }
    /* affiche le plateau victorieux */
    jeu.affiche();
}

int main(){
    int nombreJoueurs = 0;
    cout << "Nombre de joueurs humains (doit être compris entre 0 et 2):" << endl;

    cin>>nombreJoueurs; /* TODO: sécuriser les saisies, au cas où quelqu'un tape des lettres par exemple */
    switch(nombreJoueurs) {
        case 0:
            IAContreIA();
            break;
        case 1:
            joueurContreIA();
            break;
        case 2:
            joueurContreJoueur();
            break;
        default:
            cout << "nombre de joueurs invalide!" << endl;
            break;
    }

    return 0;
}
