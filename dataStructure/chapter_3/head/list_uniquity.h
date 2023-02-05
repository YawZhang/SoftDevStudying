#include "list.h"
//有序列表去重
template <typename T> Rank List<T>::uniquify(){//成批剔除重复元素，效率更高
    if( _size < 2) {
        return 0;}
    Rank oldSize = _size;
    ListNodePosi(T) p = first(); ListNodePosi(T) q;
    while (trailor != (q = p->succ)){//反复考察紧邻的节点对(p, q)
        if( p->data != q->data){
            p = q;//若互异，则转向下一区段
        }
        else{ remove(q)}//否则（雷同），删除后者
    }
    return oldSize - _size;
}