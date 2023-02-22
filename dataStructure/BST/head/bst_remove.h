#include "bst.h"
#include "bst_search.h"


template <T> bool BST<T>::remove(const T& e){
    BinNodePosi(T) x = search(e); if(!x) return false;//确认目标存在
    removeAt(x, _hot); _size--;
    updateHeightAbove(_hot);//更新_hot及其历代祖先高度
    return true;
}