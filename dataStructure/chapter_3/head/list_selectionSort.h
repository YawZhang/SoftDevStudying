#include "list.h"

template <typename T>
void List<T>::selectSort(ListNodePosi(T) p, int n){
    ListNodePosi(T) head = p->pred;
    ListNodePosi(T) tail = p;
    for( int i = 0; i < n; i++){
        tail = tail->succ;//待排序区间为(head, tail)
    }
    while(1 < n){
        ListNodePosi(T) max = selectMax(head->succ, n);
        insertAsB(tail, remove(max));//将其中最大者排在末尾
        tail = tail->pred; n--;
    }

}