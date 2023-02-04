#include "ListNode.h"


template <typename T> 
class List
{
private:
    Rank _size;//规模
    ListNodePosi(T) header, trailer;//头哨兵和尾哨兵

protected:
    void init();//列表创建时的初始化
    int clear();//清除所有列表

public:
//构造函数
    List() { init(); } //默认
    List( List<T> const& L); //整体复制列表L
//析构函数
    ~List();//释放(包含头、尾哨兵在内的)所有节点
//函数接头
    T& operator [] (Rank r) const {};
};