#include "graph.h"
#include "../chapter_4/head/queue.h"


template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s){
    reset(); int clock = 0; int v = s; //初始化
    do{
        if (UNDISCOVERED == status( v )){
            BFS( v, clock);//即从该顶点出发启动一次BFS
        }
    }while( s != (v = ( ++v % n)));//按序号检查，故不漏不重

}

template <typename Tv, typename Te>//广度优先搜索BFS算法（单个连通域）
void Graph<Tv, Te>::BFS( int v, int& clock){
    Queue<int> Q;//引入辅助队列
    status(v) = DISCOVERED; Q.enqueue(v);//初始化起点
    while(!Q.empty()){
        int v = Q.dequeue(); dTime(v) = ++clock; //取出队首顶点
        for( int u = firstNbr(v); -1 < u; u = nextNbr( v )){//枚举v的所有邻居u
            if (UNDISCOVERED == status(u)){//若u未被发现
                status(u) = DISCOVERED;//发现该顶点
                Q.enqueue(u);//该顶点入栈
                type(v, u) = TREE;//引入树边拓展支撑树
                parent(u) = v;
            }
            else{//若u已被发现，或者甚至已访问完毕，则
                type(v, u) = CROSS;//将(v, u)归类为跨边
            }
        }
    }
    status( v ) = VISITED; //至此, 当前顶点访问完毕
}