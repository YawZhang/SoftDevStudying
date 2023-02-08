#include "stach.h"


//十进制正整数n到base进制的转换（递归版）
void convert(Stack<char> S, __int64 n, int base){
        //0 < n, 1 < base <= 16, 新进制下的数位符号，可视base取值范围适当扩充
        static char digit[] = {'0', '1', '2', '3', '4', '5', '6','7','8', '9', '10', 'A', 'B', 'C', 'D', 'E', 'F'};
        while (n > 0){
            S.push(digit[ n % base]);
            n /= base;
        }
    }