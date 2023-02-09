#include "stack.h"


//对(已剔除空格的)表达式S求值, 并转换为逆波兰式RPN？
float evaluate(char * S, char& RPN){
    Stack<float> opnd, Stack<char> optr;//运算数栈、运算符栈
    optr.push('\0');//尾哨兵'\0'也作为头哨兵插首先入栈
    while(!empty(optr)){//在运算符栈非空之前，逐个初始表达式中各个字符
        if(isdigit( *S)){
            readNumber(S, opnd); append(RPN, opnd.top());//读入操作数，并将其接入入RPN末尾
        }
        else{//若当前字符为运算符
            swith(orderBetween(optr.top(), *S){//视其与栈顶运算符的优先级高低分别处理
                case '<'://栈顶优先级更低时
                {
                    optr.push(*S);//当前运算符入栈
                    S++;//表达式指针后移
                    break;
                }
                case '='://栈顶和运算符优先级相同时
                {
                    optr.pop(); S++;//脱括号, 并接受下一个字符
                    break;
                }
                case '>'://栈顶优先级更高，可实施相应计算，并将结果重新入栈
                {
                    char op = optr.pop(); append(RPN, op);//栈顶运算符出栈并续接至RPN末尾
                    if ('!' ==  op){
                        float pOpnd = opnd.pop();
                        opnd.push(calcu(op, pOpnd));//实施一元计算，结果入栈
                    }
                    else{
                        float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop();//取两个操作数
                        opnd.push(calcu(pOpnd1, op, pOpnd 2));// 实施二元计算，结果入栈
                    }
                    break;
                }
                default: exit(-1);// 逢语法错误，不做处理，直接退出
            }//swith
        }
    }//while
    return opnd.pop();//弹出并返回最后的计算结果
}