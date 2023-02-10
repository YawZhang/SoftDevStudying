#include "BinTree.h"

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x){//更新节点高度， 具体规则因树不同而异
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}//次数采用常规二叉树规则 O(1)

template <typename T>//更新v及其祖先高度
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x){
    while(x){//直到根节点为止
        updateHeight(x);
        x = x->parent;
    }
}//O(n = depth(x))