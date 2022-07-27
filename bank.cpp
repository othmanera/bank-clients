#include <iostream>
#include <string>

using namespace std ;

class client{
    protected:
    string nom;
    int CIN;
    float MT;

public:
//constructeur 
client(string n="" , int C=0 , float M=0){
    
    nom = n;
    CIN = C;
    MT = M;
}   

virtual float getMontant() =0;
virtual void afficher(){
    cout <<"Nom du client:"<< nom <<endl;
    cout <<"CIN du client:"<< CIN <<endl;
    cout <<"Montant a payer:"<< MT <<endl;
}
}; // Fin de la classe client

//Classe client comptant
class clientComptant : public client {
    
    int numCh , CodeB; 

public:
//constructeur
clientComptant(string n="" , int C=0 , float M=0 , int num=0, int code=0) : client(n,C,M)
{
    numCh = num;
    CodeB = code;
}

//getMontant
float getMontant(){
    return MT; 

}

//affichage
void afficher(){

    client :: afficher();
    cout <<"Numero du cheque:"<< numCh <<endl;
    cout <<"Code de la banque:"<< CodeB <<endl;
    
}
}; //Fin de la classe ClientComptant

//classe client crédit
class clientCredit : public client{
    float Montant_Mensualite;
    int Mensualite_Restante;
    float MontantD;

public:
//constructeur
clientCredit(string n="" , int C=0 , float M=0 ,float MM=0, int MR=0 , float MD=0) : client(n,C,M)
{
    Montant_Mensualite = MM;
    Mensualite_Restante = MR;
    MontantD = MD;
}

//affichage
void afficher(){
    client :: afficher();

    cout <<"Montant de la mensualite:"<< Montant_Mensualite <<endl;
    cout <<"Nombre de mois a payer restant:"<< Mensualite_Restante <<endl;
    cout <<"Montant de la derniere mensualite:"<< MontantD <<endl;
}

//getMontant
float getMontant(){
    if (Mensualite_Restante == 1)
        return Montant_Mensualite;
    else
        return  MontantD;
}
}; //Fin de la classe clientCredit


//fonction main

main(){

    clientComptant C;
    C.afficher();

    cout <<"------"<<endl;
    
    clientCredit Cr;
    Cr.afficher();
    }