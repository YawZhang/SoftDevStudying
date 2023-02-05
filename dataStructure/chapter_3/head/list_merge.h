#include "list.h"

template <typename T>
ListNodePosi(T) List<T>::merge(ListNodePosi(T) p, Rank n, List<T>& L, ListNodePosi(T) q, Rank m){
    ListNodePosi(T) pp = p->pred;
    while((0 < m) && ( q != p))
    {//选择较小元素归入合并列表
        if ( (0 < n) && (p->data <= q->data)){
            p = p->succ; 
            n--;
        }
        else{
            insertAsA (L.remove( (q = q->succ)->pred), p);
            m--;
        }
    }
    return p = pp->succ;
}