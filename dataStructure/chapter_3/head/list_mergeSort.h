#include "list.h"

//二路归并排序
template <typename T>
void List<T>::mergeSort(ListNodePosi(T) p, int n){
    if (n < 2) return; //若待排序列表范围足够小，则直接返回
    int m = n >> 1;//以中点为界
    //子列表初始化
    ListNodePosi(T) q = p;
    for(int i = 0; i < m; m++){
        q = q->succ;//均分列表
    }

    //开始递归进行归并排序
    mergeSort(p, m); mergeSort(q, n-m);//对前、后子列表进行排序
    p = merge(p, m, *this, q, n-m);//归并
}//注意：排序后,p依然指向归并后区间的（新）起点