#include "binnode.h"


template <typename T> BTNodePosi(T) BTree<T>::insert( const T& e) {
    BTNodePosi(T) v = search(e); if (v) return false;//确保目标节点不存在
    Rank r = _hot.key.search(e); //在节点_hot的有序关键码向量中查找合适的插入位置
    _hot.key.insert( r+1, e ); //将新关键码插至对应的位置
    _hot.child.insert ( r+2, NULL);//创建一个新空子树指针
    _size++;//更新全树规模
    solveOverflow ( _hot );//如有必要，需做分裂
    return true;
}