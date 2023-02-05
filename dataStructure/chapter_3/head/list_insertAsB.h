#include "list.h"

template <typename T> 
ListNodePosi(T) List<T>::insertAsB(ListNodePosi(T) p, T const& e){
    _size++;
    return p->insertAsPred(e);//e作为p的后继插入(After)
}