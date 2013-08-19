//#include "./src/jeu.cpp"
#include "./include/jeu.h"



int main(){
    int coup1;
    int coup2;
    jeu j;


    while(!j.fin()){
        j.affiche();
        cout<<"coup joueur 1 :"<<endl;
        cin>>coup1;
        cin>>coup2;
        j.joue(coup1,coup2);
        j.regles();
        j.affiche();
        j.repond();
        j.regles();
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
