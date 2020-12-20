//
// Created by Matteo on 13/12/2020.
//

#ifndef CONTENITORE_VETTORE_H
#define CONTENITORE_VETTORE_H

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
     * n dev'essere una potenza di due
     */
    u_int n;

public:
    class Iterator {
    private:

    public:

    };


    Vettore();
    ~Vettore();
    void operator=(const Vettore&);

    // Utility del vettore
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


#endif //CONTENITORE_VETTORE_H
