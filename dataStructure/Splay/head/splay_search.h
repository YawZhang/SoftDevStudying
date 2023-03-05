#include "spaly"


template <typename T> BinNodePosi(T) & Splay<T>::search(const T& e) {
    BinNodePosi(T) p = searchIn( _root, e, _hot=NULL);
    _root = spaly( p ? p : _hot);//将最后一个被访问节点伸展至树根
    return _root;
}//与其他BST不同，无论查找成功与否，_root都指向最后被访问的节点