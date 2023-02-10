#include "BinTree.h"
#include "../chapter_4/head/stack.h"

//迭代1：实现先序排序，V->L->R
template <typename T>
void travPre_I1( BinNodePosi(T) x, VST& visit){
    Stack<BinNodePosi(T)> s;//辅助栈
    if (x) s.push(x);//根节点入栈
    while(!s.empty()){//在栈变空前反复循环
        x = s.pop(); visit( x->data);//弹出并访问当前节点
        if (HasRChild( *x )) s.push(x->rc) ;//右孩子先入后出 R
        if (HasLChild( *x )) s.push(x->lc) ;//左孩子后入先出 L
    }
}