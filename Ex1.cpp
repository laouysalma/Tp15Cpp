
#include<iostream>
using namespace std;

class Noeud{
    public:
     int valeur;
     Noeud* suivant;

     Noeud(int v):valeur(v),suivant(nullptr){}
};
class ListeChainee{
    private:
       Noeud* tete;
    public:
       ListeChainee():tete(nullptr){}
       ~ListeChainee(){
            while (tete!=nullptr)
            {
            Noeud*tmp=tete;
            tete=tete->suivant;
            delete tmp;
            }
            
        }
        void ajouterDebut(int val){
            Noeud* nouveau=new Noeud(val);
            nouveau->suivant=tete;
            tete=nouveau;
        }
        void ajouterFin(int val){
            Noeud* nouveau=new Noeud(val);
            nouveau->suivant=nullptr;
            if(tete==nullptr){
                tete=nouveau;
            }else{
                Noeud* tmp=tete;
               while (tmp->suivant != nullptr) {
                   tmp = tmp->suivant;
               }
               tmp->suivant = nouveau;
            }

        }
        void supprimer(int valeur){
            if(tete ==nullptr)return;
            if(tete->valeur == valeur){
                Noeud* tmp = tete;
                tete = tete->suivant;
                delete tmp;
                return;  
            }
            Noeud* courant = tete;
            while (courant->suivant != nullptr && courant->suivant->valeur != valeur) {
            courant = courant->suivant;
            }
            if (courant->suivant != nullptr) {
                Noeud* temp = courant->suivant;
                courant->suivant = temp->suivant;
                delete temp;
            }
        }
        void afficher() const{
            Noeud* courant=tete;
            while(courant!=nullptr){
                cout<<courant->valeur<<" -> ";
                courant=courant->suivant;
            }
            cout<<"NULL"<<endl;
        }
        int taille(){
            int count=0;
            Noeud* courant=tete;
            while(courant!=nullptr){
                count++;
                courant = courant->suivant;
            }
            return count;


        }

};
int main(){
    ListeChainee l;
    l.ajouterDebut(13);
    l.ajouterFin(1);
    l.ajouterFin(5);
    l.ajouterDebut(9);
    l.afficher();

    cout<<"la taille de cette liste est : "<<l.taille()<<endl;

    l.supprimer(5);
    l.afficher();

    cout<<"la taille de cette liste est : "<<l.taille()<<endl;


}