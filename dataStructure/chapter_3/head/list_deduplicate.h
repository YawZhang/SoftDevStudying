#include "list.h"
//无序列表去重
template <typename T> Rank List<T>::deduplicate(){//提出无序列表中的重复节点
    if (_size < 2) return 0;//平凡列表自然无重复
    Rank oldSize = _size;//记录原规模
    ListNodePosi(T) p = first(); Rank r = 1; // p从首节点开始
    while( trailer != (p = p->succ)){//依次从首节点开始，直到末节点
        ListNodePosi(T) q = find(p->data, r, p);//在p的前r个真前驱中，查找与之雷同者
        q ? remove(q) : r++;//若存在，删除之；否则秩递增————不能remove(p)，因为需要找p->succ，容易引发错误   
    }//assert: 循环过程中的任意时刻，p的所有前驱互不相同
    return oldSize - _size;//返回列表规模变化量，即被删除元素综述
}