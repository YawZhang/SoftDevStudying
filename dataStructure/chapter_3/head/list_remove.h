#include "list.h"

template <typename T>
ListNodePosi(T) List<T>::remove(ListNodePosi(T) p){
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}