#include "binnode.h"


template <typename T> BTNodePosi(T) BTree<T>::search( const T& e) {//在B树中查找关键码e
    BTNodePosi(T) v = _root; _hot = _root;
    while (v) {
        Rank r = v->key.search(e);//在当前节点中，找到不大于e的最大关键码
        if ( (0 <= r) && (v.key[r] == e) ) return v;//成功:在当前节点中命中目标关键码
        _hot = v; v = v->child[r + 1];//否则，转入对应子树（_hot指向其父)——需要做I/O，最费时间
    }
    return NULL;//查找失败:最终抵达外部节点
}