#include "list.h"

template <typename T>  //重载下标操作符，以通过秩直接访问列表节点（虽简便，效率低，需慎用）
T& List<T>::operator []( Rank r) const{
    ListNodePosi(T) p = first(); //从首节点出发
    while( 0 < r-- ){
        p = p->succ;//顺取第r个节点
    }
    return p->data;//返回目标节点所存元素
}