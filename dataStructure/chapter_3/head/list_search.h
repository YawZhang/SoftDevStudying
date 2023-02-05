#include "list.h"
//在有序列表内节点p(可能是trailer)的n个真前驱中，找到不大于e的最后者
template <typename T> ListNodePosi(T) search(T const& e, Rank n, ListNodePosi(T) p) const { 
    //assert: 0 <= n <= rank(p) < _size
    while( 0 <= n-- ){
        if ( ( (p = p->pread)->data ) <= e) break;
    }
    return p;
}//失败时，返回区间左边界的前驱(可能是header)————调用这可用valid()判断成功与否