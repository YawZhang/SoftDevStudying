#include "BinTree.h" 

//子树中序遍历(递归版) L->V->R
template <typename T, typename VST> 
void travIn_R(BinNodePosi(T) x, VST & visit){
    if (!x) return;//根为空，则直接返回
    travIn_R(x->lc, visit);
    visit(x->data);
    tracIn_R(x->rc, visit);
} 