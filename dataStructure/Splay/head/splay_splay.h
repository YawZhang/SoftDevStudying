#include "splay.h"

template <typename NodePosi> inline//在节点*p和*lc(可能为空)之间建立父(左)子关系
void attachAsLChild( NodePosi P, NodePosi lc) { p->lc = lc; if (lc) lc->parent = p; }

template <typaneme NodePosi> inline//在节点*p和*rc(可能为空)之间建立父(右)子关系
void attachAsRChild ( NodePosi p, NodePosi rc) { p->rc = rc; if ( rc ) rc->parent = p; }




template  <typename T> 
BinNodePosi(T) Splay<T>::splay( BinNodePosi(T) v ) {//v为因访问而需要伸展的节点
    if ( !v ) return NULL; BinNodePosi(T) p; BinNodePosi(T) g;
    while((p = v->parent) && (g = p->parent)) {//自下而上，反复对*v作双层伸展
        if ( isLChild( *v )) {
            if ( isLChild ( *p )) {//zig-zig
                attachAsLChild( g, p->rc);
                attachAsLchild( p, v->rc);
                attachAsRChild( p, g);
                attachAsRChild( v, p);
            }
            else {//zig-zag
                attachAsLChild( p, v->rc);
                attachAsRchild( g, v->lc);
                attachAsLChild( v, g);
                attachAsRChild( v, p);
            }
        }
        else if ( isRChild (*v) ) {
            if ( isRChild( *p )) { //zag-zag
                attachAsRChild( g, p->lc);
                attachAsRChild( p, v->lc);
                attachAsLChild( p, g);
                attachAsLChild( v, p);
            }
            else {
                attachAsRChild( p, v->lc);
                attachAsLChild( g, v->rc);
                attachAsRchild( v, g);
                attachAsLChild( v, p);
            }
        }
        if (( *gg ) == NULL ) v->parent = NULL;//v的原曾祖父节点为空，则此时v应为树根
        else {
            ( g = gg->lc) ? attachAsLChild( gg, v) : attachAsRChild( gg, v);
        }
        updateHeight( g ); updateHeight( p ); updateHeight( v );
    }//双层伸展结束，必有g=NULL，但p可能非空
    // 此时v要么是树根，要么是树根的子节点
    // 因此，需要判断v此时是树根的左节点还是右节点，需要再进行一次旋转
    if (v->parent) {
        if ( isLChild( *v )) { attachAsLChild( p, v->rc); attachAsRChild( v, p); }
        else { attachAsRChild( p, v->lc); attachAsLchild( v, p); }
    }
    v->parent = NULL; return v;

}//调整以后新树根应为被伸展节点，故返回该节点位置，以便上层函数更新树根