
#include "./include/jeu.h"
#include "./include/IA.h"



int main(){
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
        if (jeu.coupJoueur1(coup) != SUCCES) {
            cout << "coup invalide" << endl;
            continue;
        }
        //jeu.regles();
        jeu.affiche();
        ia.repond();
        //jeu.regles();
    }
/*
    while(!j.fin()){
        //cout<<"plateau : "<<endl;
        jeu.affiche();
        cout<<"coup joueur 1 :"<<endl;
        cin>>coup1;
        cin>>coup2;
        jeu.coupJoueur1(coup1,coup2);
        jeu.regles();
        jeu.affiche();

        cout<<"coup joueur 2 :"<<endl;
        cin>>coup1;
        cin>>coup2;
        jeu.coupJoueur2(coup1,coup2);


        //j.repond();
        jeu.regles();
    }
*/
    return 0;

}
