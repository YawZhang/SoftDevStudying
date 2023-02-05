#include "list.h"

template <typename T>
void insertSort(ListNodePosi(T) p, int n){
    for(int r = 0; r < n; r++){
        insertAsAfter(search(p->data, r, p), p->data);//在有序前驱中找到不大于p的位置，插入p
        p = p->succ; remove(p->pred);//转向下一个节点
    }
}