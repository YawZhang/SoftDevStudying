#include "avl.h"

template <typename T> bool AVL<T>::remove(const T& e){
    BinNodePosi(T) &x = search(e); if (!x) return false;//确保目标存在(留意_hot设置)
    removeAt(e, _hot); _size--;//先按BST规则删除之(此后，原节点之父_hot及其祖先均可能失衡)
    for (BinNodePosi(T) g = _hot; g; g->parent){
        if (!AvlBalanced( *g )){
            //一旦发现g失衡，则（采用“3+4”算法）使之失衡，并将该子树
            g = FromParentTo(*g) = rotateAt( tallerChild( tallerChild( g )));//链接至原父亲
        }
        //由于删除造成的节点失衡经过重平衡后，其它祖先仍然有可能失衡，因此仍需要向上查找失衡节点
        //不过好在由于删除造成的节点失衡同时只能有一个节点失衡
        //这是由于删除节点失衡，则该节点一定是祖父的短子树
        updateHeight(g);//并更新其高度(注意：即使g未失衡，高度亦有可能降低->原先平衡因子为+-1,删除的为长子树节点)
    }
    return true;//删除成功
}