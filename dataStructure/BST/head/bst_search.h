#include "bst.h"
#include "bst_searchIn.h"

template <typename T> BinNodePosi(T)& BST<T>::search(const T& e){
    return searchIn(_root, e, _hot=NULL);//返回目标节点位置的引用，一遍后续插入，删除操作
}

