#include "../chapter_2/vector.h"
#define BTNodePosi(T) BTNode<T>* //B-树节点位置

template <typaname T> strunct BTNode {
    //成员
    BTNodePosi(T) parent;//父节点
    Vector<T> key;//关键码向量
    Vector<BTNodePosi(T)> child;//孩子向量（其长度总比key多1）
    //构造函数,BTNode只能作为根节点创建，而且初始化时有0个关键嘛和1个空孩子指针
    BTNode() { parent = NULL, child.insert( 0, NULL); }
    BTNode( T e, BTNodePosi(T) lc = NULL, BTNodePosi(T) rc = NULL ) {
        parent = NULL; //作为根节点，而且初始时
        key.insert( 0, e );//只有一个关键码，以及
        child.insert( 0, lc); child.insert( 1, rc);//两个孩子
        if ( lc ) lc->parent = this;
        if ( rc ) rc->parent = this;
    }
}