#include "bst.h"
#include "bst_search.h"

template <T> BinNodePosi(T) BST<T>::insert(const T& e){
    BinNodePosi(T) x = search(e); if(x) return x;
    x = new BinNode<T> (e, _hot);//创建新节点x:以e为关键码，以_hot为父
    ++_size;
    updateHeightAbove(x);//更新x及其历代祖先的高度
    return x;//新插入的节点，必为叶子
}//无论e存在与否，返回时总有x->data = e;

//无论查找与否，插入算法复杂度不会超过节点高度。O(h)