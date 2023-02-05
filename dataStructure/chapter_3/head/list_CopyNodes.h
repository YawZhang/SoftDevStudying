#include "list.h"

template <typename T> List<T> List<T>::copyNodes(ListNodePosi(T) p, int n){
    init();//创建头尾哨兵节点，并做初始化
    while (n--)
    {
        insertAsLast(p->data); 
        p = p->succ;//将起自P的n项依次作为末节点插入
    }
    
}