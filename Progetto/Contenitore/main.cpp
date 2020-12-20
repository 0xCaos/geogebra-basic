#include <iostream>
#include "Vettore.h"

int main() {
    std::cout << "Tester contenitore: INIZIO" << std::endl;

    Vettore<int> v1 = {10, 20, 23, 45, 50, 60, 80};

    //v1.erase(v1.begin());
    /*
    Vettore<int>::Iterator inizio = v1.begin();
    Vettore<int>::Iterator fine = v1.end();
    inizio+1;
    inizio+2;
    */

    v1.erase(v1.begin()+2, v1.begin()+4);

    v1.push_back(33);
    v1.push_back(33);
    v1.push_back(33);

    std::cout << "\n";
    for(auto el : v1) {
        std::cout << el << " ";
    }

    std::cout << "\n" << v1.size() << " " << v1.capacity();

}
