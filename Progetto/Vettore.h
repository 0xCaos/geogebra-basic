#ifndef CONTENITORE_VETTORE_H
#define CONTENITORE_VETTORE_H

#include <iostream>
#include <memory>

typedef unsigned int u_int;

template<class T>
class Vettore {
private:
    /**
     * Array sotto la struttura del vettore
     */
    T* arr;

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
    class iterator {
        friend class Vettore;
    private:
        T* punt;
    public:
        iterator() : punt(nullptr) {};
        iterator(T* p) : punt(p) {};
        iterator(const iterator&);
        ~iterator() = default; // va bene il distruttore di default

        T& operator*() const;
        bool operator==(iterator) const;
        bool operator!=(iterator) const;

        iterator& operator++(); // operator++ prefisso
        iterator operator++(int); // operator++ postfisso

        iterator& operator--(); // operator++ prefisso
        iterator operator--(int); // operator++ postfisso

        iterator operator+(int);
        iterator operator-(int);
    }; // end classe iterator

    class const_iterator {
    private:
        const T* punt;
    public:
        const_iterator() : punt(nullptr) {};
        const_iterator(const T* p) : punt(p) {};
        //const_iterator(const_iterator&);
        ~const_iterator() = default;

        const T& operator*() const;
        bool operator==(const_iterator) const;
        bool operator!=(const_iterator) const;

        const_iterator& operator++(); // operator++ prefisso
        const_iterator operator++(int); // operator++ postfisso

        const_iterator& operator--(); // operator++ prefisso
        const_iterator operator--(int); // operator++ postfisso

        const_iterator operator+(int) const;
        const_iterator operator-(int) const;

        const_iterator(iterator);

    }; // end classe const_iterator

    Vettore();
    Vettore(const Vettore&);
    Vettore(const std::initializer_list<T>&);
    Vettore(int, T);

    ~Vettore();

    Vettore& operator=(const Vettore&);
    Vettore& operator=(const std::initializer_list<T>&);

    // per discriminare la begin() e end() di "iterator" hanno la marcatura senza il const
    iterator begin() noexcept;
    iterator end();

    // le funzioni che si riferiscono a un "const_iterator" le marchiamo const (MATCH MAKING)
    const_iterator begin() const;
    const_iterator end() const;

    void push_back(const T&);
    T pop_back();

    T& operator[](u_int) const;

    /**
     * Elimina l'elemento puntato dall'Iterator nell'array
     * @return Iterator alla cella successiva a quella eliminata
     */
    iterator erase(iterator);  // modificare in Const_Iterator
    /**
     * Overloading di erase(Iterator) con un range di elementi,
     * cancella tutti gli elementi nel range compreso tra i due iterator
     * [first, last) => (last escluso)
     * @return Iterator alla cella successiva all'ultima eliminata
     */
    iterator erase(iterator, iterator);
    /**
     * Resizes the container so that it contains n elements.
     * If n is smaller than the current container size, the content is reduced to its first n elements,
     * removing those beyond (and destroying them).
     * If n is greater than the current container size, the content is expanded by inserting at the end
     * as many elements as needed to reach a size of n.
     * If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
     */
    void resize(u_int, const T& = T());

    /**
     * Svuota il vettore di tutti i suoi elementi
     * (A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change)
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

    /**
     * Funzione per l'inserimento di elementi in un vettore
     * @return an iterator that points to the first of the newly inserted elements
     */
    iterator insert(iterator, const T&);
    iterator insert(iterator, u_int, const T&);
    iterator insert(iterator, std::initializer_list<T>);
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
T& Vettore<T>::iterator::operator*() const {
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
    }
    return *this;
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
typename Vettore<T>::iterator Vettore<T>::begin() noexcept {
    return iterator(&(arr[0]));
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::end() {
    return iterator(&(arr[vsize]));
}

template<class T>
u_int Vettore<T>::capacity() const {
    return vcapacity;
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::erase(Vettore::iterator first) {
    if(first.punt && first!=end()){
        iterator prec = first;
        iterator succ = first+1;
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
typename Vettore<T>::iterator Vettore<T>::erase(Vettore::iterator first, Vettore::iterator last) {
    if(first.punt && last.punt && (first!=last)){
        iterator ultimo(last);
        while(first!=ultimo){
            erase(first);
            ultimo--;
        }
        return ultimo;
    }
    return last;
}

template<class T>
T Vettore<T>::pop_back() {
    return *(erase(end()-1));
}

template<class T>
void Vettore<T>::clear() {
    erase(begin(), end());
}

template<class T>
bool Vettore<T>::empty() const {
    return vsize==0;
}

template<class T>
void Vettore<T>::resize(u_int new_size, const T& val) {
    if(new_size >= 0){
        if(new_size > vsize){
            while(vsize < new_size)
                push_back(val);
        } else {
            erase(begin()+new_size, end());
        }
    }
}

template<class T>
bool Vettore<T>::iterator::operator==(Vettore::iterator it) const {
    return punt == it.punt;
}

template<class T>
bool Vettore<T>::iterator::operator!=(Vettore::iterator it) const {
    return punt != it.punt;
}

template<class T>
typename Vettore<T>::iterator& Vettore<T>::iterator::operator++() {
    punt++;
    return *this;
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::iterator::operator++(int) {
    iterator aux(*this);
    operator++();
    return aux;
}

template<class T>
typename Vettore<T>::iterator& Vettore<T>::iterator::operator--() {
    punt--;
    return *this;
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::iterator::operator--(int) {
    iterator aux(*this);
    operator--();
    return aux;
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::iterator::operator+(int x) {
    return iterator(punt+x);
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::iterator::operator-(int x) {
    return iterator(punt-x);
}

template<class T>
Vettore<T>::iterator::iterator(const Vettore::iterator & it) {
    punt = it.punt;
}

template<class T>
const T& Vettore<T>::const_iterator::operator*() const {
    return *punt;
}

template<class T>
bool Vettore<T>::const_iterator::operator==(Vettore::const_iterator it) const {
    return punt == it.punt;
}

template<class T>
bool Vettore<T>::const_iterator::operator!=(Vettore::const_iterator it) const {
    return punt != it.punt;
}

template<class T>
typename Vettore<T>::const_iterator& Vettore<T>::const_iterator::operator++() {
    punt++;
    return *this;
}

template<class T>
typename Vettore<T>::const_iterator Vettore<T>::const_iterator::operator++(int) {
    const_iterator aux(*this);
    operator++();
    return aux;
}

template<class T>
typename Vettore<T>::const_iterator& Vettore<T>::const_iterator::operator--() {
    punt--;
    return *this;
}

template<class T>
typename Vettore<T>::const_iterator Vettore<T>::const_iterator::operator--(int) {
    const_iterator aux(*this);
    operator--();
    return aux;
}

template<class T>
typename Vettore<T>::const_iterator Vettore<T>::const_iterator::operator+(int x) const {
    return const_iterator(punt+x);
}

template<class T>
typename Vettore<T>::const_iterator Vettore<T>::const_iterator::operator-(int x) const {
    return const_iterator(punt-x);
}

template<class T>
Vettore<T>::const_iterator::const_iterator(Vettore<T>::iterator it) {
    const T* aux = it.punt;
    punt = aux;
}


template<class T>
typename Vettore<T>::const_iterator Vettore<T>::begin() const {
    return const_iterator(&(arr[0]));
}

template<class T>
typename Vettore<T>::const_iterator Vettore<T>::end() const {
    return const_iterator(&(arr[vsize]));
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::insert(Vettore::iterator pos, const T& x) {
    if(pos == end()) {
        push_back(x);
        pos = end();
    } else {
        if(vsize+1 > vcapacity){
            if(vcapacity == 0) vcapacity = 1;
            else vcapacity *= 2;

            T* tmp = new T[vcapacity];      // creo il nuovo array
            iterator scorri = begin();
            u_int i = 0;
            while(scorri!=pos && i < vsize){
                tmp[i] = arr[i];
                scorri++; i++;
            }

            if(scorri!=pos)
                throw(std::out_of_range("The position used is out of range")); // posizione non presente nell'array (UB)
            else {
                iterator aux = tmp+i;
                tmp[i] = x;
                while (i < vsize){
                    tmp[i+1] = arr[i];
                    i++;
                }

                if(arr) delete[] arr;                   // elimino il vecchio array

                arr = tmp;
                pos = aux;
            }
        } else {

            iterator prec = end()-1;
            iterator succ = end();

            while(prec != pos-1 && prec != begin()-1){
                *succ = std::move(*prec);
                prec--; succ--;
            }

            if(prec == begin()-1) {
                throw(std::out_of_range("The position used is out of range"));
            } // posizione non presente nell'array (UB)

            *pos = x;
        }
        vsize++;
    }
    return pos;
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::insert(Vettore::iterator pos, u_int n, const T& x) {
    for(u_int i=0; i < n; i++)
        pos = insert(pos,x);

    return pos;
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::insert(Vettore::iterator pos, std::initializer_list<T> li) {
    for(auto x : li){
        pos = insert(pos,x);
        pos++;
    }

    return pos;
}


#endif //CONTENITORE_VETTORE_H
