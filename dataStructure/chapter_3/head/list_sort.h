#include "list.h"

template <typename T> void List<T>::sort(ListNodePosi(T) p, int n){
    //列表区间排序
    switch (rand() % 3)
    {
    case 1: insertionSort (p, n); break;//插入排序
    case 2: selectionSort (p, n); break;//选择排序
    
    default: mergeSort( p, n); break;//归并排序
    }
}