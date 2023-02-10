#include <iostream>
using namespace std;

template <typename T> struct BinNode;
#define BinNodePosi(T) BinNode<T>* ; //节点位置

#define stature(p) (p ? p->height : -1); //节点高度（与“空树高度-1”的约定相统一）
typedef enum{ RB_RED, RB_BLACK} RBColor; //节点颜色


template <typename T> struct BinNode{//二叉树节点模板
    T data; //数值
    int height;//高度
    BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;//父节点及左、右孩子
    int npl;//Null Path Length(左式堆，也可以用height代替)
    RBColor color;//颜色 红黑树

    //构造函数
    BinNode() : 
        parent( NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p=NULL, BinNodePosi(T) lc=NULL, BinNodePosi(T) rc=NULL,
            int h = 0, int l = 1; RBColor c = RB_RED) :
            data(e) , parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}
    
    //操作接口
    int size(); //子树规模
    BinNodePosi(T) insertAsLC(T const &);//作为左孩子插入新节点
    BinNodePosi(T) insertAsRC(T const &);//作为右孩子插入新节点
    BinNodePosi(T) succ(); //（中序遍历意义下）当前节点的直接后继
    template <typename VST> void travLevel(VST &);  //子树层次遍历
    template <typename VST> void travPre(VST &);    //子树先序遍历
    template <typename VST> void travIn(VST &);     //子树中序遍历
    template <typename VST> void travPost(VST &);   //子树后序遍历
    

    

}

