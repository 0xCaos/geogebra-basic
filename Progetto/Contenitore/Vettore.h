//
// Created by Matteo on 13/12/2020.
//

#ifndef CONTENITORE_VETTORE_H
#define CONTENITORE_VETTORE_H

#include <iostream>
#include <memory>

typedef unsigned int u_int;

template<class T>
class Vettore {
friend class Iterator;
private:
    /**
     * Array sotto la struttura del vettore
     */
    T* arr;
    //std::unique_ptr<T[]> arr;
    /**
     * Size del Vettore
     * vsize indica il numero di elementi presenti nel Vettore
     */
    u_int vsize;
    u_int vcapacity;

    /**
     * Funzione void privata richiamata dalle funzioni di inserimento che
     * alloca un nuovo array con capacità -> vcapacity * 2
     * ed effettua la copia di tutti gli elementi nel nuovo array
     */
    void rialloca_array();

public:
    class Iterator {
        friend class Vettore;
    private:
        T* punt;
    public:
        Iterator() : punt(nullptr) {};
        explicit Iterator(T* p) : punt(p) {};
        Iterator(const Iterator&);


        //Iterator&operator=(const Iterator&); Va bene l'assegnazione di default
        // va bene il distruttore di default

        T& operator*() const;
        bool operator==(Iterator) const;
        bool operator!=(Iterator) const;

        Iterator& operator++(); // operator++ prefisso
        Iterator operator++(int); // operator++ postfisso

        Iterator& operator--(); // operator++ prefisso
        Iterator operator--(int); // operator++ postfisso

        Iterator operator+(int) const;
        Iterator operator-(int) const;
    }; // end classe Iterator

    Vettore();
    Vettore(const Vettore&);
    Vettore(const std::initializer_list<T>&);
    Vettore(int, T);

    ~Vettore();

    Vettore& operator=(const Vettore&);
    Vettore& operator=(const std::initializer_list<T>&);

    Iterator begin() const;
    Iterator end() const;

    void push_back(const T&);
    T pop_back();

    T& operator[](u_int) const;

    /**
     * Elimina l'elemento puntato dall'Iterator nell'array
     * @return Iterator alla cella successiva a quella eliminata
     */
    Iterator erase(Iterator);  // modificare in Const_Iterator
    /**
     * Overloading di erase(Iterator) con un range di elementi,
     * cancella tutti gli elementi nel range compreso tra i due iterator
     * [first, last) => (last escluso)
     * @return Iterator alla cella successiva all'ultima eliminata
     */
    Iterator erase(Iterator, Iterator);
    /**
     * Cambia la dimensione (capacity) del vettore
     */
    void resize();

    /**
     * Svuota il vettore di tutti i suoi elementi
     */
    void clear();

    /**
     * size()
     * @return : il numero degli oggetti presenti nel Vettore
     */
    u_int size() const;

    /**
     * capacity()
     * @return : il numero di celle disponibili nell'array prima del resize
     */
    u_int capacity() const;

    /**
     * empty()
     * @return : true sse il vettore non contiene oggetti
     */
    bool empty() const;


};

template<class T>
Vettore<T>::Vettore() : arr(nullptr), vsize(0), vcapacity(0) {}

template<class T>
Vettore<T>::Vettore(const Vettore& v2) : Vettore() {
    *this = v2;
}

template<class T>
Vettore<T>::Vettore(int dim, T init) : arr(new T[dim]), vsize(dim), vcapacity(dim)  {
    for(int i=0; i<dim; i++)
        arr[i] = init;
}

template<class T>
Vettore<T>::Vettore(const std::initializer_list<T>& li) : arr(new T[li.size()]), vsize(li.size()), vcapacity(li.size()){
    int i=0;
    for(auto el : li){
        arr[i] = el;
        i++;
    }
}

template<class T>
Vettore<T>::~Vettore() {
    if(arr)
        delete[] arr;
}

template<class T>
T& Vettore<T>::Iterator::operator*() const {
    return *punt;
}

template<class T>
void Vettore<T>::rialloca_array() {
    // setto il nuovo valore per la capacità
    if(vcapacity == 0) vcapacity = 1;
    else vcapacity *= 2;

    T* tmp = new T[vcapacity];      // creo il nuovo array
    for(u_int i=0; i < vsize; i++)
        tmp[i] = arr[i];

    if(arr) delete[] arr;                   // elimino il vecchio array

    arr = tmp;
}

template<class T>
void Vettore<T>::push_back(const T& el) {
    if(vsize+1 > vcapacity){
        rialloca_array();
    }

    //*(end()) = el; SINIGAGLIA ha detto che non era bello vedere end() deferenziato
    arr[vsize] = el;
    vsize++;
}

template<class T>
T& Vettore<T>::operator[](u_int pos) const {
    return arr[pos];
}

template<class T>
u_int Vettore<T>::size() const {
    return vsize;
}

template<class T>
Vettore<T>& Vettore<T>::operator=(const Vettore& v2) {
    if(this != &v2){
        if(arr) delete[] arr;
        vsize = v2.vsize;
        vcapacity = v2.vcapacity;
        arr = new T[vcapacity];
        for(u_int i=0; i < vsize; i++)
            arr[i] = v2.arr[i];

        return *this;
    }
}

template<class T>
Vettore<T>& Vettore<T>::operator=(const std::initializer_list<T>& li) {
    delete[] arr;
    vsize = li.size();
    vcapacity = vsize;
    arr = new T[vcapacity];
    int i=0;
    for(auto el : li){
        arr[i] = el;
        i++;
    }

    return *this;
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::begin() const {
    return Iterator(&(arr[0]));
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::end() const {
    return Iterator(&(arr[vsize]));
}

template<class T>
u_int Vettore<T>::capacity() const {
    return vcapacity;
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::erase(const Vettore::Iterator first) {
    if(first.punt && first!=end()){
        Iterator prec = first;
        Iterator succ = first+1;
        while (succ != end()) {
            *prec = std::move(*succ);
            ++prec; ++succ;
        }
        vsize--;
        return prec;
    }
    return first;
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::erase(const Vettore::Iterator first, const Vettore::Iterator last) {
    if(first.punt && last.punt && (first!=last)){
        //Iterator scorri(first);
        Iterator ultimo(last);
        while(first!=ultimo){
            erase(first);
            ultimo--;
        }
        return ultimo;
    }
    return last;
}

template<class T>
bool Vettore<T>::Iterator::operator==(Vettore::Iterator it) const {
    return punt == it.punt;
}

template<class T>
bool Vettore<T>::Iterator::operator!=(Vettore::Iterator it) const {
    return punt != it.punt;
}

template<class T>
typename Vettore<T>::Iterator& Vettore<T>::Iterator::operator++() {
    punt++;
    return *this;
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::Iterator::operator++(int) {
    Iterator aux(*this);
    operator++();
    return aux;
}

template<class T>
typename Vettore<T>::Iterator& Vettore<T>::Iterator::operator--() {
    punt--;
    return *this;
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::Iterator::operator--(int) {
    Iterator aux(*this);
    operator--();
    return aux;
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::Iterator::operator+(int x) const {
    return Iterator(punt+x);
}

template<class T>
typename Vettore<T>::Iterator Vettore<T>::Iterator::operator-(int x) const {
    return Iterator(punt-x);
}

template<class T>
Vettore<T>::Iterator::Iterator(const Vettore::Iterator & it) {
    punt = it.punt;
}

#endif //CONTENITORE_VETTORE_H
