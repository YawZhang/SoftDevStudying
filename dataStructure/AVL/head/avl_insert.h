#include "avl.h"


template <typename T> BinNodePosi(T) AVL<T>::insert(conse T& e){
    BinNodePosi(T) x = search( e ); if(x) return x;//确认目标节点不存在
    BinNodePosi(T) xx = x = new BinNode<T> (e, _hot); _size++;//创建新节点x
    //此时若x的父亲_hot增高，则其祖父有可能失衡
    for (BinNodePosi(T) g = _hot; g; g->parent){
        if(!AvlBalanced( *g )){//一旦发现祖先g失衡，则开始复衡
        FromParentTo( *g ) = rotateAt( tallerChild ( tallerChild( g )));//重新接入子树
        break;//g复衡后，局部子树必然复原，其祖先亦如此
        }
        else{//否则（g依然平衡），只需要简单地
            updateHeight(g);//更新其高度
        }
    }//至多需要一次调整;若真调整，则全树高度必然复原

    return xx;//返回新节点位置
}//无论e是否存在原书中，总有AVL::insert(e)-data == e;