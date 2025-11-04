#include<iostream>
using namespace std;

class File{
    private:
      int* data ;
      int debut,fin, taille,capacite;
    public:
       File(int cap) {
        capacite = cap;
        data = new int[capacite];
        debut = 0;
        fin = -1;
        taille = 0;
       }
       ~File() {
        delete[] data;
       }
      void enfiler(int val) {
        if (taille == capacite) throw "File pleine";
        fin = (fin + 1) % capacite;
        data[fin] = val;
        taille++;
      
      }
      int  defiler() {
        if (taille == 0) throw "File vide";
        int val = data[debut];
        debut = (debut + 1) % capacite;
        taille--;
        return val;
      }
      bool estVide() const {
        return taille == 0;
      }
      bool estPleine(){
        return taille == capacite;
      }
      void afficher() const {
        for (int i = 0; i < taille; i++) {
            int index = (debut + i) % capacite;
            cout << data[index] << " ";
        }
        cout << endl;
}

};
int main(){
    File f(5);
    f.enfiler(2);
    f.enfiler(42);
    f.enfiler(1);
    f.afficher();

    f.defiler();
    f.afficher();
}