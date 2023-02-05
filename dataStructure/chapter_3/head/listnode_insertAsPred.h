#include "ListNode.h"


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e){
    ListNodePosi(T) x = new ListNode(e, pred, this);//创建新节点
    pred->succ = x;//将该节点作为原节点前驱的后继
    pred = x; //将该节点作为原节点的前驱。PS: 次序不能颠倒
    return x;//返回新节点的位置
}