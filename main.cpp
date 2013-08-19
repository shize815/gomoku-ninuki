//#include "./src/jeu.cpp"
#include "./include/jeu.h"
#include "./include/IA.h"



int main(){
    int coup1;
    int coup2;
    jeu j;
    IA ia;
    ia.setjeu(&j);

    while(!j.fin()){
        j.affiche();
        cout<<"coup joueur 1 :"<<endl;
        cin>>coup1;
        cin>>coup2;
        j.joue(coup1,coup2);
        //j.regles();
        j.affiche();
        ia.repond();
        //j.regles();
    }
/*
    while(!j.fin()){
        //cout<<"plateau : "<<endl;
        j.affiche();
        cout<<"coup joueur 1 :"<<endl;
        cin>>coup1;
        cin>>coup2;
        j.joue(coup1,coup2);
        j.regles();
        j.affiche();

        cout<<"coup joueur 2 :"<<endl;
        cin>>coup1;
        cin>>coup2;
        j.joue2(coup1,coup2);


        //j.repond();
        j.regles();
    }
*/
    return 0;

}
