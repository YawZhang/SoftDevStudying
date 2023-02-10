#include "BinTree.h"

//二叉树层次遍历算法 先进先出, V-L-R
template <typename T, typename VST> 
void BinNode<T>::travLevel(VST& visit){
    Queue<BinNodePosi(T)> Q;//辅助队列
    Q.enqueue(this);//根节点入列
    while(!Q.empty()){//在队列变空之前，反复迭代
        BinNodePosi(T) x = Q.dequeue();//队首节点出列
        visit(x->data);//访问该节点
        if (hasLChild( *x )) Q.enqueue(x->lc);//左孩子入列
        if (hasRChild( *x )) Q.enqueue(x->rc);//右孩子入列
    }
    //虽然访问完首节点，左右孩子先后入列，
    //下次访问左孩子，左孩子的左右孩子先后入列
    //再下次访问，先访问右孩子，再右孩子的左右孩子先后入列
    //再再下次，访问左孩子的左孩子，即 先上而下，先左向右访问
    
}