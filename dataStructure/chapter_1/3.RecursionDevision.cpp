#include <iostream>
#include <algorithm>
using namespace std;

void MaxValue_recursionDevision(int A[], int lo, int hi, int &max1, int &max2)
{
    if (lo+2==hi)
    {
        // T(2)=1
        if (A[max1=lo]<A[max2=lo+1]) // 直接先初始化再比较，若为逆序排列，直接交换二者位置
        {
            swap(max1, max2);
        }
        return;
        
    }
    if(lo+3 == hi)
    {
        // T(3)<=3
        if (A[max1=lo]<A[max2=lo+1]) // 直接先初始化再比较，若为逆序排列，直接交换二者位置
        {
            swap(max1, max2);
        }
        if (A[max2] < A[lo+2])  // 对
        {  
            if(A[max1]<A[max2=lo+2])
            {
                swap(max1, max2);
            }
        }
        return;
    }
    int mi = (lo+hi) >> 1; 
    int max1L; int max2L; MaxValue_recursionDevision(A, lo, mi, max1L, max2L); // 初始化2个最大值
    int max1R; int max2R; MaxValue_recursionDevision(A, mi, hi, max1R, max2R);
    if (A[max1L] > A[max1R]){
        max1 = max1L;
        max2 = (A[max2L > max1R]) ? max2L: max1R;
    }
    else
    {
        max1 = max1R;
        max2 = (A[max2R > max1L]) ? max2R: max1L;
    }
}



int main()
{
    // int arr[] = {1, 2, 9};
    int arr[] = {1, 2, 9, 3, 8, 7, 4, 5, 0, 6, 11, 212 ,12 };
    int len = sizeof(arr) / sizeof(arr[1]);
    int max1=0; int max2=0;
    MaxValue_recursionDevision(arr, 0, len, max1, max2);
    cout << "max1 = " << arr[max1] << endl;
    cout << "max2 = " << arr[max2] << endl;
    return 0;

}
