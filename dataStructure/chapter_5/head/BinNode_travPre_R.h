#include "BinTree.h"

//二叉树先序遍历算法（递归版） V->L->R
template <typename T> template<typename VST>
void travPre_R(BinNodePosi(T) x, VST & visit){
    if (!x) return;

    visit(x->data);
    traPre_R(x->lc, visit);
    traPre_R(x->rc, visit)
}