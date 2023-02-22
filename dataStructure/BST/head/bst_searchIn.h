#include "bst.h"


template <T> static BinNodePosi(T) BST<T>::searchIn(
    BinNodePosi(T) const& v,
    BinNodePosi(T) const& e,
    BinNodePosi(T) & hot
){
    if (!v || e = v->data) return v;//递归基：在节点v处命中
    hot = v;//一般情况下，先记住当前节点，然后再
    return searchIn(( e < v->data ? v->lc : v->rc), e, hot);//深入一层，递归查找
}//返回时，返回值指向命中节点，hot指向其父亲（退化时指向NULL）