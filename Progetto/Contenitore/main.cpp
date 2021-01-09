#include <iostream>
#include "Vettore.h"
#include <vector>
using namespace std;

// ERASE --> gestione out of range?
// CLEAR --> aggiusta la size ma non la capacity
// CAPACITY --> potenza di 2 più vicina alla size?
// Operator[i] --> 0 <= i < size()

int main() {
/*
    Vettore<int> v1 = {10, 20, 30, 40, 50};

    for(int i=51; i<60; ++i)
        v1.push_back(i);

    cout << "----- TEST #1 -----" << endl;

    cout << "----- BEFORE CLEAR -----" << endl;
    cout << "STAMPA ELEMENTI: ";
    for(auto el : v1)
        cout << el << " ";
    cout << endl;
    cout << "SIZE: " << v1.size() << endl;
    cout << "CAPACITY: " << v1.capacity() << endl;
    cout << "EMPTY?: " << v1.empty() << endl;

    cout << "BEGIN: " << *(v1.begin()) << endl;
    cout << "BEGIN == END? " << (v1.end() == v1.begin()) << endl;

    cout << endl;

    v1.clear();
    cout << "----- AFTER CLEAR -----" << endl;
    cout << "STAMPA ELEMENTI: ";
    for(auto el : v1)
        cout << el << " ";
    cout << endl;
    cout << "SIZE: " << v1.size() << endl;
    cout << "CAPACITY: " << v1.capacity() << endl;
    cout << "EMPTY?: " << v1.empty() << endl;

    cout << "BEGIN: " << *(v1.begin()) << endl;
    cout << "BEGIN == END? " << (v1.end() == v1.begin()) << endl;
    cout << endl;

    cout << "----- TEST #2 -----" << endl;
    Vettore<string> v2 = {"Midro", "Noghez", "Spola", "PNX", "Mamma"};
    cout << "STAMPA ELEMENTI: ";
    for(auto el : v2)
        cout << el << " ";
    cout << endl;
    v2.erase(v2.begin()+2);
    cout << "ERASE Begin+2: ";
    for(auto el : v2)
        cout << el << " ";
    v2.insert(v2.begin()+2, {"Add1", "Add2", "Add3"});
    cout << endl;
    cout << "INSERT initializer list: ";
    for(auto el : v2)
        cout << el << " ";
    v2.insert(v2.begin()+5, 3, "PIOLO");
    cout << endl;
    cout << "INSERT Same element: ";
    for(auto el : v2)
        cout << el << " ";
    cout << endl << endl;

    cout << "----- TEST #3 -----" << endl;
    Vettore<string> v3 = {"Padre", "Figlio", "Spirito"};
    cout << "STAMPA ELEMENTI: ";
    for(auto el : v3)
        cout << el << " ";
    cout << endl;
    cout << endl;
    cout << "----- v2 Props -----" << endl;
    cout << "SIZE: " << v2.size() << endl;
    cout << "CAPACITY: " << v2.capacity() << endl;
    cout << "EMPTY?: " << v2.empty() << endl;
    cout << endl;
    cout << "----- v3 Props -----" << endl;
    cout << "SIZE: " << v3.size() << endl;
    cout << "CAPACITY: " << v3.capacity() << endl;
    cout << "EMPTY?: " << v3.empty() << endl;
    cout << endl;
    cout << "v2[100]: " << v2[100] << "... (Con i=-1 va in SIGSEGV)" << endl;
    cout << endl;
    cout << "----- TEST #4 -----" << endl;
    cout << "RESIZE v2 - Size=5: ";
    v2.resize(5, "Bombus");
    for(auto el : v2)
        cout << el << " ";
    cout << endl;
    cout << "----- v2 Props -----" << endl;
    cout << "SIZE: " << v2.size() << endl;
    cout << "CAPACITY: " << v2.capacity() << endl;
    cout << "EMPTY?: " << v2.empty() << endl;
    cout << endl;
    cout << "RESIZE v2 - Size=10: ";
    v2.resize(10, "Bombus");
    for(auto el : v2)
        cout << el << " ";
    cout << endl;
    cout << "----- v2 Props -----" << endl;
    cout << "SIZE: " << v2.size() << endl;
    cout << "CAPACITY: " << v2.capacity() << endl;
    cout << "EMPTY?: " << v2.empty() << endl;
    cout << endl;
    */
    vector<int> std = {1,2,3,4,5};
    Vettore<int> nostro = {1,2,3,4,5};
    cout << "ELEMENTI STD: ";
    for(auto el : std)
        cout << el << " ";
    cout << endl;
    cout << "ELEMENTI NOSTRO: ";
    for(auto el : nostro)
        cout << el << " ";
    cout << endl;
    cout << "----- ERASE -----" << endl;
    std.erase(std.begin(), std.end());
    nostro.erase(nostro.begin(), nostro.end());
    cout << "ELEMENTI STD: ";
    for(auto el : std)
        cout << el << " ";
    cout << endl;
    cout << "ELEMENTI NOSTRO: ";
    for(auto el : std)
        cout << el << " ";
    cout << endl;
    cout << "std.begin(): " << *std.begin() << endl;
    cout << "nostro.begin(): " << *nostro.begin() << endl;
}

