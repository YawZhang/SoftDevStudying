#include "BinTree.h"

template <typename T, typename VST>
void visitLongLeftBranch(BinNodePosi(T) x, 
                         VST& visit, 
                         Stack<BinNodePosi(T)> S){
    while(x){//反复访问左链
        visit(x->data);//访问当前节点
        S.push(x->rc);//右孩子入栈(将来逆序出栈)
        x = x ->lc;//沿左侧链下行
    }//只有右孩子、NULL可能入栈
}

template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST& visit){
    Stack<BinNodePosi(T)> S;//辅助栈
    
    while(true){//以右子树为单位，逐批访问节点
        visitLongLeftBranch(x, visit, S);//访问子树x的左侧链，右子树入栈缓冲
        if( S.empty) break;//栈空即退出
        x = S.pop();//弹出下一子树的根
    }
}