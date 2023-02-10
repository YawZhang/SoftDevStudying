#include "BinTree.h"


template <typename T>
void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T) S){
    while(x){
        S.push(x);//根节点反复入栈
        x = x->lc;//沿左分支深入
    }
}


template <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST& visit){
    Stack<BinNodePosi(T) S;//缓冲栈
    while(true){//反复入栈
        goAlongLeftBranch(x, S);//从当前节点出发，逐批入栈
        if(S.empty()) break;//直至所有节点处理完毕
        x = S.pop();//x的左子树或为空，或已遍历（等效于空），故可以
        visit(x->data);//立即访问之
        x = x->rc;//再转向其右子树（可能为空，留意处理手法）
    //若右子树为空，goAlong 直接跳出，x转向上一个节点
    }

}
