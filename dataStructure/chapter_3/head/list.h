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
    Rank size() const { return _size; } //规模
    bool empty() const { return _size <= 0; } //判空
    T& operator [] (Rank r) const {};//重载[], 使List能以秩的方式进行访问元素
    ListNodePosi<T> first() const { return header->succ; } //首节点位置
    ListNodePosi<T> last() const { return trailer->pred; } //末节点位置
    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const{};//查找
    ListNodePosi(T) insertAsFirst(T const& e){};//e当首节插入
    ListNodePosi(T) insertAsLast(T const& e){};//e当末节插入
    ListNodePosi(T) insertAsA(ListNodePosi(T) p, T const& e){};//e当p的后继插入
    ListNodePosi(T) insertAsB(ListNodePosi(T) p, T const& e){};//e当p的前驱插入
    List<T> copyNodes(ListNodePosi(T) p, int n) {};//列表内部复制方法
    T remove(ListNodePosi(T) p) {};//刪除节点
};