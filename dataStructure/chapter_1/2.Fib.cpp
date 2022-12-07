#include <iostream>
using namespace std;

int fib_recursion(int n)
{
    // 自顶而上递归，过于消耗时间做重复的工作，如：fib(1), fib(2)
    return (2>n)? n: fib_recursion(n-1) + fib_recursion(n-2);
}

int fib_iteration(int n)
{
    int g = 0, f = 1;
    while(0<n--)
    {
        g = g + f;
        f = g - f;
    }
    // if (n>0)
    // {
    //     for(int i=0; i<n; i++)
    //     {
    //         g = g + f;
    //         f = g - f;
    //     }
    // }
    return g;
}

int main()
{
    for (int i=0; i<10; i++)
    {
        int ret = fib_iteration(i);
        cout << "fib(" << i << ")=" << ret <<  endl;
    }
    return 0;
}
