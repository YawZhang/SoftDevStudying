#include "stack.h"

//括号匹配（迭代版）
template <typename T> 
bool paren(const char exp[], int lo, int hi){
    Stack<char> S;//使用栈记录已发现但未匹配的左括号
    for(int i = lo; i < hi; i++){
        switch (exp[i]){//左括号直接进栈，有括号若与栈顶失配, 则表达式必不匹配
            case '(': case '[': case '{': S.push(exp[i]); break;
            case ')': if (S.empty() || S.pop() != '(') return false; break;
            case ']': if (S.empty() || S.pop() != '[') return false; break;
            case '}': if (S.empty() || S.pop() != '}') return false; break;
            default: break;
        }
    }
    return S.empty(); //表达式扫描过后，栈中若仍存在(左)括号，则不匹配，否则(栈空)匹配
}

