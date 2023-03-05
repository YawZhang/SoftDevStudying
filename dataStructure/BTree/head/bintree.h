#include "binnode.h"



template <typename T> class BTree {
protected: 
    int _size;//存放的关键码总数
    int _order;//B-树的阶次，至少为3----指定时创建，一般不能修改
    BTNodePosi(T) _root;//根节点
    BTNodePosi(T) _hot;//search最后访问的非空的节点位置
    void solveOverflow ( BTNodePosi(T) );//因插入而上溢后的分裂处理
    void solveUnderflow( BTNodePosi(T) );//因删除而下溢后的合并处理
public:
    BTNodePosi(T) search(const T& e);//查找
    BTNodePosi(T) insert( const T& e);//插入
    bool remove ( const T& e);//删除 
}