#include "list.h"

template <typename T> 
ListNodePosi(T) List<T>::insertAsA(ListNodePosi(T) p, T const& e){
    _size++;
    return p->insertAsSucc(e);//e作为p的后继插入(After)
}