#include "list.h"
//从起始位置p的n各元素中选择最大者
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n){
    ListNodePosi(T) max = p;//初始化最大值为首节点
    for (ListNodePosi(T) cur = p; 1 < n; n--){
        if (!lt((cur = cur->succ)->data, max->data)){//succ >= max
            max = cur;//更新最大元素位置
        }
    }
    return max;
}