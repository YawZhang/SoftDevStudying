#include "spaly.h"



template <typename T> bool Splay<T>::remove (const T& e ) {
    if ( !_root || ( e != search ( e )->data )) return false;//确定目标已存在
    BinNodePosi(T) w = _root;
    if ( !HasLChild( *_root )) {//若无左子树，直接删除
        _root = _root->rc; if ( _root ) _root->parent = NULL;
    }
    else if ( !HasRChild( *_root )) {//若无右子树，直接删除
        _root = _root->lc; if ( _root ) _root->parent = NULL;
    }
    else {
        BinNodePosi(T) lTree = _root->lc;//先备份一个左子树
        lTree->parent = NULL;
        _root->lc = NULL;//暂时切除左子树
        _root = _root->rc;
        search ( w->data );//在右子树中找一个最大者
        _root->lc = lTree; lTree->parent = _root;//只需要将原子树接回去
    }
    release( w->data ); release ( w ); _size--;
    if (_root) updateHeight (_root);
    return true;
}