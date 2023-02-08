#include <iostream>
using namespace std;
#include "vector.h"


template <typename T>
class Stack public Vector{
public: //size() empty() 以及其他开放接口，均可直接沿用
    void push(T const& e){ insert( size(), e)}; //入栈: 等效于将新元素插入向量末元素
    T pop() {return remove(size() - 1);}; // 出栈: 等效于将向量末元素删除
    T &top() { return (*this)[size() - 1]};// 取顶: 等效于直接返回向量末元素
};