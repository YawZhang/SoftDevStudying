#include "list.h"


template <typename T> List<T>::~List()
{
    clear();//清空列表
    delete header;//释放头哨兵节点
    delete trailer;//释放尾哨兵节点
}

template <typename T> int List<T>::clear(){//清空列表
    int oldSize = _size;
    while (0 < _size){//反复删除首节点，直至列表为空
        remove(header->succ);
    }
    return oldSize;
}//O(n)，线性正比于列表规模 
