#include "BinTree.h"

template <typename T>
BinNodePosi(T) insertAsRoot( T const& e){
    _size = 1;
    return _root = new BinNode<T> (e); //将e作为根节点插入空的二叉树
}