#pragma once
#include <iostream>
using namespace std;

typedef int Rank;//秩
#define ListNodePosi(T) ListNode<T>*

template <typename T>
struct ListNode
{
    //成员
    T data; //数值
    ListNodePosi(T) pred;//前驱
    ListNodePosi(T) succ;//后继

    //构造函数
    ListNode() {}//针对header和trailer的构造
    ListNode( T e, ListNodePosi p = NULL, ListNodePosi s = NULL)
     : data(e), pred(p), succ(s) {}//默认构造

    //操作接口
    ListNodePosi(T) insertAsPred(T const& e);//紧靠当前节点之前插入新节点
    ListNodePosi(T) insertAsSucc(T const& e);//紧靠当前节点之后插入新节点
};
