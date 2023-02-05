#include "list.h"

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e){
    _size++;
    return header->insertAsSucc(e);
}