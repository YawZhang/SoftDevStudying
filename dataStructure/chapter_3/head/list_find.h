#include "list.h"

//在无序列表内节点p（可能是trailer）的n个（真）前驱中，找到等亍e的最后者
template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const{
    while(0 < n--){ // (assert 0 <= n <= rank(p) < _size) 对于p的前n个真前驱，从右往左
        if (e == (p = p->pred)->data){//逐个对比，直至命中或范围越界
            return p;
        }
    }
    return NULL;//p越界意味未命中，查找失败
}//查找失败，返回NULL