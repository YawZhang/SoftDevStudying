#include "stack.h"


//栈混洗,两个栈A和B, 加入一个空栈S, A中元素只能放入S中, S中元素只能放入A中，若进过n次
//可以从A -> B, 则A和B是栈混洗

template <typename T>
bool stack_permutation(Stack<T> A, Stack<T> B){
    Stack<T> S;//先创建一个中转栈S
    for( int i = 0; i < A.size(); i++){//遍历A栈每个元素
        S.push(A.pop());//将A栈顶push进S
        while(!s.empty() && s.top == B.top){//若S非空且S栈顶和B栈顶相同, 则S和B均出栈
            S.pop(); B.pop(); //
        }
    }
    //若S空, 意味经过N次push和pop A成功转移到B, A和B为栈混洗, 反之则不是
    if (!S.empty()) return false;
    else return true;
}