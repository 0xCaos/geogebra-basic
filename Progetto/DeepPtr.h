#ifndef DEEPPTR_H
#define DEEPPTR_H

#include <iostream>

typedef unsigned int u_int;

template<class T>
class DeepPtr {
private:
    T* p;
public:

    /**
     * @brief Costruttore di Default
     * --> p punta a nullptr
     */
    DeepPtr();

    /**
     * @brief Costruttore profondo (da puntatore)
     * --> p punta a _p clonato
     */
    DeepPtr(T* _p);

    /**
     * @brief Costruttore di copia profonda
     * --> p punta a _p.p clonato
     */
    DeepPtr(const DeepPtr& _p);

    /**
     * @brief Assegnazione profonda
     * @return
     */
    DeepPtr& operator=(const DeepPtr&);

    /**
     * @brief Distruttore Profondo
     */
    ~DeepPtr();

    /**
     * @brief Getter del puntatore
     * @return p
     */
    T* get() const;

    /**
     * @brief Scambia p con _dp.p
     * --> this controllerà l'ex puntatore di _dp e viceversa
     */
    void swap(DeepPtr& _dp);

    /**
     * @brief Rilascia p, sostituendolo con un puntatore nullo
     * @return p
     */
    T* release();

    /**
     * @brief Distrugge p sostituendolo con _p
     */
    void reset(T* _p=nullptr);

    /**
     * @brief operator *
     * @return ritorna p dereferenziato, se p non è nullo
     */
    T& operator*() const;

    /**
     * @brief operator ->
     * @return ritorna p, se p non è nullo
     */
    T* operator->() const;

    /**
     * @brief operator bool
     * @return true se p non è nullptr, altrimenti false
     */
    explicit operator bool() const;
};

template<class T>
DeepPtr<T>::DeepPtr() : p(nullptr) {}

template<class T>
DeepPtr<T>::DeepPtr(T* _p) : p(_p->clone()) {}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr& _dp) : p(_dp.p->clone()) {}

template<class T>
DeepPtr<T>&  DeepPtr<T>::operator=(const DeepPtr& _dp) {
    if (this != &_dp) {
        delete p;
        p = _dp.p->clone();
    }
    return *this;
}

template<class T>
DeepPtr<T>::~DeepPtr() {
    delete p;
}

template<class T>
T* DeepPtr<T>::get() const { return p; }

template<class T>
void DeepPtr<T>::swap(DeepPtr& _dp) {
    using std::swap;
    swap(p, _dp->p);
}

template<class T>
T* DeepPtr<T>::release() {
    T* _p = get();
    p = nullptr;
    return _p;
}

template<class T>
void DeepPtr<T>::reset(T* _p) {
    using std::swap;
    swap(p, _p);
    delete _p;
}

template<class T>
T& DeepPtr<T>::operator*() const {
    if (get())
        return *get();
    else
        return 0;
}

template<class T>
T* DeepPtr<T>::operator->() const {
    if (get())
        return get();
    else
        return 0;
}

template<class T>
DeepPtr<T>::operator bool() const { return get()!=nullptr; }

#endif // DEEPPTR_H
