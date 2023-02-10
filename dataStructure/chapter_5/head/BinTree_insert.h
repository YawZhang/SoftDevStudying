#include "BinTree.h"

template <typename T>
BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e)//e作为x的左孩子（原无）插入
{
    _size++;//规模加一
    x->insertAsLC(e);//节点左孩子插入算法
    updateHeightAbove(x);//更新节点高度
    return x->lc;

}


template <typename T>
BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e)//e作为x的右孩子（原无）插入
{
    _size++;//规模加一
    x->insertAsRC(e);//节点左孩子插入算法
    updateHeightAbove(x);//更新节点高度
    return x->rc;
}