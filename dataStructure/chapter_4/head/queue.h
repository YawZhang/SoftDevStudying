#include <iostream>
using namespace std;
#include "../chapter_3/head/list.h"

template <typename T>
class Queue: public List{
public:
    T dequeue(){return remove(first())};//出队:首部删除
    void enqueue( T const& e){insertAsLast(e)};//入队: 尾部插入
    T& front(return first()->data);//队首
}