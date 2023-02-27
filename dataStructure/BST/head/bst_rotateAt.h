#include "bst.h"

/**********************************************************************************
* BST节点旋转变换统一算法（三节点，四子树），返回调整之后的局部子树根节点的位置
* 注意：虽然子树根会正确指向上层节点（如果存在），但反向联结必须由上层函数完成
***********************************************************************************/


template <typename T> BinNodePosi(T) rotateAt( BinNodeTree(T) v) {
    //对x及其父亲，祖父做统一旋转调整
    BinNodePosi(T) p = v->parent; 
    BinNodePosi(T) g = p->parent;

    if (IsLChild( *p )){
        // zig
        if (IsLChild( *v )){
            // zig-zig
            p->parent = g->parent;
            return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }
        else{
            //zig-zag
            v->parent = g->parent;
            return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
        }
    }
    else{
        //zag
        if (IsRChild( *v )){
            // zag-zag
            p->parent = g->parent;
            return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        }
        else{
            //zag-zig
            v->parent = g->parent;
            return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
    }

}