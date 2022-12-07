#include <iostream>
using namespace std;

int binaryRecursion(int A[], int lo, int hi)
{
    // 区间范围 A[lo, hi]
    if (lo == hi) return A[lo];
    
    int mi = (lo + hi) >> 1 ;
    return binaryRecursion(A, lo, mi) + binaryRecursion(A, mi+1, hi);
}

int arrSum(int A[], int n)
{
    int num = 0;
    for (int i=0; i<n; i++)
    {
        num += i;
    }
    return num;
}

int main()
{
    int arr[] = {1, 2, 9, 3, 8, 7, 4, 5, 0, 6};
    int len = sizeof(arr) / sizeof(arr[1]);
    int sum = binaryRecursion(arr, 0, len-1);
    cout << sum << endl;

    int ans = arrSum(arr, len);
    cout << ans << endl;
    return 0;
}
