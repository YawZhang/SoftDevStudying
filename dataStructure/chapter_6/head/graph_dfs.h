#include "graph.h"
#include "../chapter_4/head/queue.h"

template <typename Tv, typename Te>//深度优先搜索算法（全图）
void Graph<Tv, Te>::dfs(int s){
    reset(); int clock = 0; int v = s; //初始化
    do{
        if (UNDISCOVERED == status( v )){
            DFS( v, clock);//即从该顶点出发启动一次BFS
        }
    }while( s != (v = ( ++v % n)));//按序号检查，故不漏不重
}


template <typename Tv, typename Te>//广度优先搜索DFS算法（单个连通域）
void Graph<Tv, Te>::DFS( int v, int& clock){
    status(v) = DISCOVERED; dTime = ++clock;//发现该顶点
    for(int u = firstNbr(v); -1 < u; u = nextNbr(v, u)){//枚举所有v的邻居u
        switch (status(u)){//并视其状态分别处理
            case UNDISCOVERED:{//尚未发现u,意味着支撑树可在此拓展
                type(v, u) = TREE;
                parent(u) = v;
                DFS(u, clock);
                break;
            }
            case DISCOVERED:{//u已发现,但尚未被访问完备，应属被后代指向祖先
                type(v, u) = BACKWARD;
                break;
            }
            default://u已访问完毕（VISIT, 有向图）,则视承继关系分为向前边或跨边
            {
                type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
                break;
            }
        }
    }
    status(v) = VISITED; fTime = ++clock;//至此，当前顶点v方告访问完毕
}