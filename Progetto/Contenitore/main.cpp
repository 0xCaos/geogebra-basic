#include <iostream>
#include "Vettore.h"
#include <vector>

int main() {
    std::cout << "Tester contenitore: INIZIO" << std::endl;
    /*
    Vettore<int> v1 = {10};
    Vettore<std::pair<int, int>> vett_coppie;

    vett_coppie.push_back({2,2});
    vett_coppie.push_back({3,3});
    vett_coppie.push_back({4,4});

    std::cout << "Prima stampa \n";
    for(auto el : vett_coppie) {
        std::cout << "(" << el.first << ", " << el.second << ") ";
    }

    //vett_coppie.resize(10); // costruttore di default per val
    vett_coppie.resize(10, {7,7}); // costruttore di copia per val

    std::cout << "\nSeconda stampa \n";
    for(auto el : vett_coppie) {
        std::cout << "(" << el.first << ", " << el.second << ") ";
    }

    std::cout << "\n" << vett_coppie.size() << " " << vett_coppie.capacity();
     */

    Vettore<int> v1 = {10, 20, 30, 40, 50};
    Vettore<int> v3;
    std::vector<int> v2 = {77, 77, 77, 40, 50};

    //v1.insert(v1.begin(),77);

    v1.insert(v1.end()-1,{6,7,8,9});
    //v2.insert(v2.begin()-1, 77);
    //v1.insert(v1.begin()+2, 66);


    v3 = v1;
    for(auto el : v3)
        std::cout << el << " ";

    std::cout << "\n";
    std::cout << v3.size() << " " << v3.capacity();
}
