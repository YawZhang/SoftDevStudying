#include <iostream>
using namespace std;
#include "BinNode.h" 

template <typename T> class BinTree{
protected:
    int _size; //规模
    BinNodePosi(T) _root;//根节点
    virtual int updateHeight(BinNodePosi(T) x);//更新节点x的高度
    void updateHeightAbove(BinNodePosi(T) x);//更新节点x及其祖先的高度
public:
    BinTree() : _size(0), _root(NULL) {} ;//构造函数
    ~BinTree() {if ( 0 < _size) remove(_root);}; //析构函数
    int size() {return _size;} ;//规模
    bool empty() const {return !_root; }; //判空
    BinNodePosi(T) root() {return _root; };//树根
    BinNodePosi(T) insertAsRoot( T const& e);//插入根节点
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);//e作为x的左孩子（原无）插入
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);//e作为x的右孩子（原无）插入


}