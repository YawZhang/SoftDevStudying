#include "BinTree/BinTree.h" //引入BinTree


template <typename T> class BST : public BinTree<T> {//由BinTree派生BST模板
protected:
    BinNodePosi(T) _hot; //“命中”节点的父亲，该节点的设置，有助于插入和搜索的实现
    BinNodePosi(T) connect34(//按照“3 + 4”
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
        BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T);
    )
    BinNodePosi(T) rotateAt( BinNodeTree(T) v);//对x及其父亲，祖父做统一旋转调整
public:
    virtual BinNodePosi(T) & search( const T& e);//查找
    virtual BinNodePosi(T) insert( const T& e);//插入
    virtual bool remove(const T& e) ;//删除
    static BinNodePosi(T) & searchIn(BinNodePosi(T) v, const T& e, BinNodePosi(T) & hot);
    BinNodePosi(T) removeAt(BinNodePosi(T) x, BinNodePosi(T) _hot) {};
}
