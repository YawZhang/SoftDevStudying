#include "BinNode.h"


template <typename T>
int BinNode<T>::size() {//后代总数，亦即以其为根的子树的规模
    int s = 1;//计入本身
    if (lc) s += lc->size(); //递归计入左子树规模
    if (rc) s += rc->size(); //递归计入右子树规模
} //O(n = |size| )