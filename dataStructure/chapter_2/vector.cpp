#include <iostream>
#include <string>
using namespace std;
using Rank = int;
#define DEFAULT_CAPACITY 3

// 向量
template <typename T>
class Vector
{  

private:
    Rank _size; Rank _capacity; T* _elem;
public:
    Vector(int c = DEFAULT_CAPACITY)
    {
    _elem = new T[_capacity=c]; _size = 0;
    }// 默认构造
    Vector( T const* A, Rank lo, Rank hi);// 数组区间复制
    Vector(Vector<T> const & V, Rank lo, Rank hi);// 向量区间复制    
    Vector(Vector<T> const* V);// 向量整体复制
    ~Vector(){delete[] _elem;}// 释放内部空间
    Rank size(){return _size;}// 返回向量大小
    void copyFrom(T const * A, Rank lo, Rank hi); // Vector内部的复制函数
    void expand(); // 扩容算法

    // 元素访问，延续数组的访问形式 A[r]
    T& operator[](Rank r){return _elem[r];} // 由于返回值为T&，因此可以作为左值 V[r] = (T)(2x+3)
    // const T operator[](Rank r){return _elem[r];} // 只能作为右值 T x = V[r]

    Rank insert(Rank r, T const & e);// 向量插入算法
    Rank remove(Rank lo, Rank hi);// 向量区间删除
    T remove(Rank r);//单元素删除，借助区间删除算法
    Rank find(T const &e, Rank lo, Rank hi) const;// 查找元素
    void deduplicate();// 向量去重
    void traverse( void (* visit) ( T &)); // 函数指针实现遍历
    template<typename VST> void traverse(VST visit); // 函数对象实现遍历
    int disordered() const; // 判断序列是否为顺序排列
    int uniquit

};

/**********************************************
 * 数组区间复制
***********************************************/
template<typename T>
Vector<T>::Vector( T const* A, Rank lo, Rank hi)
    {
        copyFrom(A, lo, hi);
    }

/**********************************************
 * 向量区间复制
***********************************************/
template<typename T>
Vector<T>::Vector(Vector<T> const & V, Rank lo, Rank hi)
{
    copyFrom(V._elem, lo, hi);
}

/**********************************************
 * 向量整体复制
***********************************************/
template<typename T>
Vector<T>::Vector(Vector<T> const* V)
{
    copyFrom(V->_elem, 0, V._size);
}

/**********************************************
 *  Vector内部的复制函数
***********************************************/
template<typename T>
void Vector<T>::copyFrom(T const * A, Rank lo, Rank hi) // A中元素不至于被篡改
{
    _elem = new T[_capacity=max(DEFAULT_CAPACITY, 2*(hi - lo))]; // 分配新空间
    for(_size=0; lo<hi; _size++, lo++)
    {
        _elem[_size] = A[lo]; // A[lo, hi) 内的元素，逐一复制到_elem[0, hi-lo)
    }
}

/**********************************************
 *  扩容算法
***********************************************/
template <typename T>
void Vector<T>::expand()
{
    if(_size < _capacity) return; // 尚未满员，不必扩充
    _capacity = max(DEFAULT_CAPACITY, _capacity); // 不低于最小容量
    T* oldElem = _elem; _elem = new T[_capacity <<= 1]; // 加倍扩容
    // T* oldElem = _elem; _elem = new T[_capacity += INCREMENT]; // 固定增量扩容
    for(Rank i = 0; i< _size; i++)  // 复制原向量内容
    {
        _elem[i] = oldElem[i]; // 逐一拷贝， T为基本类型，或已重载赋值操作运算符"="
    } 
    delete [] oldElem; // 释放原空间
}// 得益于向量的封装，使得扩容之后数据区的物理地址改变，而不会出现野指针


/**********************************************
 *  向量插入算法
***********************************************/
template <typename T>
Rank Vector<T>::insert(Rank r, T const & e)// 向量插入算法
    {
        expand(); // 若有必要，进行扩容 ，当向量中存满数据，即_size = _capacity，则需要扩容
        for(Rank i=_size; r<i; i--) // O(n-r)
        {
            _elem[i] = _elem[i-1];
        }
        _elem[r]=e; _size++; return r; // 置入新元素，更新容量，返回秩
    }

/**********************************************
 *  向量区间删除
***********************************************/
template <typename T>
Rank Vector<T>::remove(Rank lo, Rank hi)
{
    if(lo == hi) return -1; // 出于效率考虑，单独处理退化情况
    while(hi<_size){_elem[lo++] = _elem[hi++];} // O(n-hi): [hi, n)顺次迁移
    _size = lo;;
    return hi-lo; // 返回删除元素数目
}


/**********************************************
 *  向量单元素删除
***********************************************/
template<typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r]; // 拷贝一份
    remove(r, r+1); // 借助区间删除算法，删除单个元素
    return e;
}// O(n-4)


/**********************************************
 *  查找
***********************************************/
template<typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while((lo<hi--) && (e != _elem[hi])){} // 逆向查找
    return hi;
}

/**********************************************
 *  向量元素去重
***********************************************/
template<typename T>
void Vector<T>::deduplicate()
{
    Rank oldSize = _size;
    for (Rank i=1; i<_size;)
    {
        if (find(_elem[i], 0, i) < 0)
            i++;
        else{ remove(i);}
    }
}


/**********************************************
 *  函数指针实现遍历
***********************************************/
template<typename T>
void Vector<T>::traverse( void (* visit) ( T &))
{
    for(Rank i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
}

/**********************************************
 *  函数对象实现遍历
***********************************************/
template<typename T> template<typename VST>
void Vector<T>::traverse(VST visit)
{
    for(Rank i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
}

/**********************************************
 *  向量是否有序排列
***********************************************/
template <typename T>
int Vector<T>::disordered() const
{
    int n = 0; // 计数器
    for (int i = 1; i < _size; i++)
    {
        n += (_elem[i-1] > _elem[i]); // 逆序则计数
    }
    return n;
}

/**********************************************
 *  向量遍历打印算法
***********************************************/
template<typename T>
void printVector(Vector<T> V)
{
    for (Rank i=0; i<V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}


template<typename T>
struct Increase
{
    void operator()(T&e){e++;}
};

template <typename T>
void increase(Vector<T> &V)
{
    V.traverse(Increase<T>());
}


void test01()
{
    Vector<int> myV(6);
    for (int i=0; i<7; i++)
    {
        Rank temp=0;
        temp = myV.insert(i, i);
    }
    printVector(myV);
    // Rank ret = myV.remove(3);
    // myV.insert(5, 2);
    int sorded = myV.disordered();
    if (sorded=0)
    {
        cout << "该向量为逆序" << endl;
    }
    else{cout << "该向量为顺序" << endl;}

}




int main()
{

    test01();
    return 0;
}
