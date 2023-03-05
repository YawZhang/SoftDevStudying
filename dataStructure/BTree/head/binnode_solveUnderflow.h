#include "binnode.h"


template <typename T> void BTree<T>::solveUnderflow( BTNodePosi(T) v) {
    if (( _order + 1) / 2 <= v->child.size() ) return;//递归基
    BTNodePosi(T) p = v->parent;
    if ( !p ) {//递归基：已到根节点，没有孩子的下限
        if ( !v->key.size() && v->child[0] ) { 
            //倘若作为树根的v已不含关键码，却有唯一的非空孩子，则
            _root = v->child[0]; v->child[0]->parent = NULL;//该节点被跳过
            v->child[0] = NULL; release( v );//并因不再有用而被销毁
        }
        return;
    }
    Rank r = 0; while ( p->child[r] != v) r++;
    

}