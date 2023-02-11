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
    Vector ( Rank c = DEFAULT_CAPACITY, Rank s = 0, T v = 0 ) //容量为c、规模为s、所有元素初始为v
    { _elem = new T[_capacity = c]; for ( _size = 0; _size < s; _elem[_size++] = v ); } //s<=c
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
    Rank insert ( T const& e ) { return insert ( _size, e ); } //默认作为末元素插入
    Rank remove(Rank lo, Rank hi);// 向量区间删除
    T remove(Rank r);//单元素删除，借助区间删除算法
    Rank find(T const &e, Rank lo, Rank hi) const;// 查找元素
    void deduplicate();// 向量去重
    void traverse( void (* visit) ( T &)); // 函数指针实现遍历
    template<typename VST> void traverse(VST visit); // 函数对象实现遍历
    int disordered() const; // 判断序列是否为顺序排列
    int uniquify_low(); // 低效版 有序序列去重
    int uniquify(); // 高效版 有序序列去重
    void bubbleSort_A(Rank lo, Rank hi); //冒泡排序算法（基本版）
    void bubbleSort_B(Rank lo, Rank hi); //冒泡排序算法（改进版：提前终止版）
    void bubbleSort_C(Rank lo, Rank hi); //冒泡排序算法（最终版）
    void merge(Rank lo, Rank mi, Rank hi); //二路并归排序算法

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
    while(hi<_size){
        _elem[lo++] = _elem[hi++];} // O(n-hi): [hi, n)顺次迁移
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
 *  低效版 有序序列去重
***********************************************/
template <typename T>
Rank Vector<T>::uniquify_low()
{
    Rank oldSize = _size, i=1;
    while( i < _size ){
        (_elem[i - 1] == _elem[i]) ? remove(i): i++;
        }
    return oldSize - _size;
}

/**********************************************
 *  高效版 有序序列去重
***********************************************/
template <typename T>
Rank Vector<T>::uniquify()
{
    Rank i=0, j=0; // 各对互异“相邻”元素的秩
    while(++j<_size) // 逐一扫描
    {
        // 跳过雷同者;
        if(_elem[i] != _elem[j]){
            _elem[++i] = _elem[j]; //发现不同元素时，向前移至紧邻与前者右侧
            } 
    }
    _size = ++i;
    cout << "j=" << j  << "  i=" << i << endl;
    return j-i; // 返回删除的元素个数
}

/**********************************************
 *  二分查找（版本A):在有序的向量区间[lo, hi)内查找元素e，0 <= lo <= hi <=_size
***********************************************/
template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi){
    while (lo < hi){  // 每步迭代做两次比较判断，有三个分支
        Rank mi = (lo + hi) >> 1; // 以中点为轴,(区间宽度折半,等效于其数值表示的右移一位)
        if (e < S[mi]) hi = mi; // 深入前半段[lo, mi)继续查找
        else if (S[mi] > e) lo = mi; // 深入后半段[mi, hi)继续查找
        else return mi; // 在mi处命中
    } // 查找成功可以提前终止
    return -1; // 查找失败
} // 不足:有多个命中元素时,不能保证返回秩最大者;查找失败时,简单的返回-1,而不能提示失败的位置


/**********************************************
 *  二分查找（版本B):在有序的向量区间[lo, hi)内查找元素e，0 <= lo <= hi <=_size
***********************************************/
template <typename T> static Rank binSearch_B(T* S, T const& e, Rank lo, Rank hi){
    while (1 < hi - lo){ // 每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
        Rank mi = (lo + hi) >> 1; // 以中点为轴(区间宽度折半，等效于其数值表示的右移一位)
        (e < S[mi]) ? hi = mi : lo = mi; // 经比较后确定深入[lo, mi)或[mi, hi)
    }// 出口时hi= lo+1, 查找区间仅含一个元素A[lo]
    return e < S[lo] ? lo - 1 : lo; // 返回位置，总是不超过e的最大者
} // 有多个命中元素时, 返还秩的最大者; 查找失败时, 简单返回-1, 而不能指示失败的位置


/**********************************************
 *  二分查找（版本C):正确性，符合语义要求，返回秩的最大者
***********************************************/
template <typename T> static Rank binSearch_C(T* S, T const& e, Rank lo, Rank hi){
    while (1 < hi - lo){ // 每步迭代仅需做一次比较判断，有两个分支；成功查找不能提前终止
        Rank mi = (lo + hi) >> 1; // 以中点为轴(区间宽度折半，等效于其数值表示的右移一位)
        (e < S[mi]) ? hi = mi : lo = mi + 1; // 经比较后确定深入[lo, mi)或(mi, hi)
    }// 出口时hi= lo+1, 查找区间仅含一个元素A[lo]
    return --lo;//至此，[lo]为大于e的最小者，故[lo-1]即为不大于e的最大者
} // 有多个命中元素时, 返回最靠后者; 查找失败时, 简单返回失败的位置


/**********************************************
 *  向量的冒泡算法（基本版）
***********************************************/ 
template <typename T>
void Vector<T>::bubbleSort_A(Rank lo, Rank hi){
    while(lo < --hi){ // 反复冒泡扫描
        for(Rank i = lo; i < hi; i++){ // 逐个检查相邻元素
            if (_elem[i] > _elem[i + 1]){//若逆序
                swap(_elem[i], _elem[i + 1]);// 经交换，局部有序
            }
        }
    }
}


/**********************************************
 *  向量的冒泡算法（提前终止版）
***********************************************/ 
template <typename T>
void Vector<T>::bubbleSort_B(Rank lo, Rank hi){
    for(bool sorted = false; sorted = !sorted; hi--){ // 反复冒泡扫描
        for(Rank i = lo; i < hi; i++){ // 逐个检查相邻元素
            if (_elem[i] > _elem[i + 1]){//若逆序
                sorted = false;//意味尚未整体有序
                swap(_elem[i], _elem[i + 1]);// 需要交换
            }
        }
    }
}


/**********************************************
 *  向量的冒泡算法（跳跃版）
***********************************************/ 
template <typename T>
void Vector<T>::bubbleSort_C(Rank lo, Rank hi){
    for(Rank last; lo < hi; hi = last){ // 反复冒泡扫描
        for(Rank i = lo + 1, last = lo; i < hi; i++){ // 逐个检查相邻元素
            if (_elem[i] > _elem[i + 1]){//若逆序
                swap(_elem[i], _elem[(i + 1)]); // 则交换
                last = i + 1; // 且记录最后交换的位置
            }
        }
    }
}


/**********************************************
 *  向量的二路并归排序算法（对各自的[lo, mi)和[mi, hi)进行排序, 此时B,C应为有序序列，用递归算法排序
***********************************************/ 
template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi){
    // 初始化子向量
    Rank i = 0; T* A = _elem + lo;
    Rank j = 0; lb = mi - lo; T* B = new T[lb];
    for (Rank i = 0; i < lb; i++){
        B[i] = A[i];
    }
    Rank k = 0; lc = hi - mi; T*C = _elem + mi;

    // 开始归并
    while((j < lb ) && (k < lc)){//反复比较B和C的首元素
        A[i++] = (B[j++] <= C[k++]) ? B[j++] : C[k++];//小者优先归入A中
    }
    while(j<lb){//若C先耗尽，
        A[i++] = B[j++];//将B残余的元素归入A中
        //若B先耗尽，则后续元素不用再归并
    }
    delete[] B;
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
    int index = 0;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            Rank temp=0;
            temp = myV.insert(index, i*3);
            index++;
        }
        ;
    }
    printVector(myV);
    int ret = myV.uniquify_low();
    // int ret = myV.uniquify();
    cout << "ret = " << ret << endl;
    printVector(myV);

}




int main()
{

    test01();
    return 0;
}
