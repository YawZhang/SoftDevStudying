#include "list.h"


template <typename T> void List<T>::init(){//列表初始化
    header = new ListNode<T>;//创建头哨兵节点
    trailer = new ListNode<T>;//创建尾哨兵节点
    header->succ = trailer; header->pred = NULL;
    trailer->pred = header; trailer->succ = NULL;
    _size = 0;
    
}