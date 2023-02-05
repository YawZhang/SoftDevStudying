#include "ListNode.h"


template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e){
    ListNodePosi(T) x = new ListNode(e, this, succ);//创建新节点
    succ->pred = x;//将该节点作为原节点后继的前驱
    succ = x; //将该节点作为原节点的后继。PS: 次序不能颠倒
    return x;//返回新节点的位置
}