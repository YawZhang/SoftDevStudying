#include "binnode.h"


template <typename T> void BTree<T>::solveOverflow( BTNodePosi(T) v) {
    if ( _order >= v->child.size() ) return;//递归基: 当前节点未上溢
    Rank s = _order / 2;//轴点，此时应该有_order = v->key.size() = v->child.size() - 1
    BTNodePosi(T) u = new BTNode<T>();//创建一个新的节点
    for ( Rank j = 0; j < _order - s - 1; j++) {//v右侧_order-s-1个孩子及关键码分裂成右侧节点u
        u->key.insert( j, v->key[s+1]);
        u->child.insert( j, v->child[s+1])
    }
    u->child[_order - s -1] =  v->child.remove( s + 1 );//移动v最右侧孩子
    if (u->child[0]) {
        for (Rank j = 0; j < _order -s; j++) {
            u->child[j]->parent = u;//把u的每个孩子和父节点相联接
        }
    }
    BTNodePosi(T) p = v->parent;//找到节点v的父亲
    if ( !p ) { _root = p  = new BTNode<T>(); p->child[0] = v; v->parent = p; }//如果v为根节点，则创建新根节点
    Rank r = 1 + p.key.search( v.key[0]);//p中指向u的指针的秩
    p->key.insert( r, v.key.remove( s ));//轴点关键码上升
    p->child.insert( r + 1, u); u->parent = p;//
    solveOverflow( p );

}