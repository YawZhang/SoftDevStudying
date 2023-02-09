#include <iostream>
using namespace std;
#include "paren.h"


int main(){

    char c[] = {'(', '[', '{', '}', ']', ')'};
    bool sss = paren(c, 0, 6);
    cout << sss << endl;

    return 0;
}