#include "binnode.h"


template <typename T> bool BTree<T>::remove( const T& e) {
    BTNodePosi(T) v = search( e ); if ( !v ) return false;
    Rank r = v.key.search( e );
    if ( v-child[0] ) {//若为叶子节点
        BTNodePosi(T) u = v->child[ r + 1 ];//在右子树中一直向左，找e的后继
        while ( u->child[0] ) u = u->child[0];//
        v->key[r] = u->key[0]; v = u ; r = 0;//并与之交换位置
    }//至此v必然位于最底层，且其中第r个关键码就是待删除的节点

    v.key.remove( r ); v->child.remove( r + 1 ); _size--;
    solveUnderflow( v );//如有必要，需做旋转合并
    return true;
}