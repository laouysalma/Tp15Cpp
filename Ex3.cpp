#include <iostream>
#include <list>
#include <string>
using namespace std;

class TableHachage {
private:
    int taille;
    list<pair<int, string>>* table;

    int hachage(int cle) const {
        return cle % taille;
    }

public:
    TableHachage(int t) : taille(t) {
        table = new list<pair<int, string>>[taille];
    }

    ~TableHachage() {
        delete[] table;
    }

    void inserer(int cle, const string& valeur) {
        int index = hachage(cle);
        for (auto& p : table[index]) {
            if (p.first == cle) {
                p.second = valeur;
                return;
            }
        }
        table[index].push_back({cle, valeur});
    }

    string rechercher(int cle) const {
        int index = hachage(cle);
        for (const auto& p : table[index]) {
            if (p.first == cle) return p.second;
        }
        return "Clé non trouvée";
    }

    void supprimer(int cle) {
        int index = hachage(cle);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == cle) {
                table[index].erase(it);
                return;
            }
        }
    }

    void afficher() const {
        for (int i = 0; i < taille; ++i) {
            cout << i << ": ";
            for (const auto& p : table[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    TableHachage tab(5);
    tab.inserer(2, "T");
    tab.inserer(1, "B");
    tab.inserer(4, "H");
    tab.afficher();
    cout << tab.rechercher(1) << endl;
    tab.supprimer(1);
    tab.afficher();
}
