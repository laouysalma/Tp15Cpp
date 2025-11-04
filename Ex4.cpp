#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <class T>
class Pile {
private:
    vector<T> elements;
public:
    void empiler(T element) {
        elements.push_back(element);
    }
    T depiler() {
        if (estVide()) throw runtime_error("Pile vide");
        T val = elements.back();
        elements.pop_back();
        return val;
    }
    T sommet() const {
        if (estVide()) throw runtime_error("Pile vide");
        return elements.back();
    }
    bool estVide() const {
        return elements.empty();
    }
    void inverser() {
        reverse(elements.begin(), elements.end());
    }
    void afficher() const {
        for (auto it = elements.rbegin(); it != elements.rend(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};

int main() {
    Pile<int> p1;
    p1.empiler(1);
    p1.empiler(2);
    p1.empiler(3);
    p1.afficher();
    p1.inverser();
    p1.afficher();

    Pile<string> p2;
    p2.empiler("Salut");
    p2.empiler("Salma");
    p2.empiler("!");
    p2.afficher();
    cout << p2.depiler() << endl;
    p2.afficher();

    Pile<double> p3;
    p3.empiler(1.1);
    p3.empiler(2.2);
    p3.empiler(3.3);
    p3.afficher();
}
