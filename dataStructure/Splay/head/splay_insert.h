#include "splay.h"

 template <typename T> BinNodePosi(T) Splay<T>::insert (const T& e ) {
    if ( !_root ) { _size++; return _root = new BinNode<T> e; }
    if ( e == search(e)->data ) return _root;//确定目标不存在
    _size++; BinNodePosi(T) t = _root;//创建新节点。以下调整<=7个指针以完成局部重构
    if ( _root->data < e ) {
        t->parent = _root = new BinNode<T> (e, NULL, t, t->rc);
        if (HasRChild( *t )) { t->rc->parent = _root; t->rc = NULL; }
    }
    else {
        t->parent = _root = new BinNode<T> (e, NULL, t->lc, t);
        if (HasLChild( *t )) { t->lc-parent = _root; t->lc = NULL; }
    }
    updateHeightAbove( *t );
    return _root;
    