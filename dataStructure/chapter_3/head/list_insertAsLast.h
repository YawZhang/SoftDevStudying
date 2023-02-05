#include "list.h"

template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e){
    _size++;
    return trailer->insertAsPred(e);
}