#include <iostream>
using namespace std;

typedef enum { UNDISCOVERED, DISCOVERED, VISITED} VStatus;// 顶点状态
typedef enum { UNDETERMINED, TREE, FORWARD, BACKWARD, CROSS} ETypes;//边在遍历树中所属的类型


template <typename Tv, typename Te>
class Graph {
private:
    void reset(){//所有顶点和边的辅助信息复位
        for (int i = 0; i < n; i++){
            status( i ) = UNDISCOVERED;//状态
            dTime( i ) = fTime( i ) = -1;//时间标签
            parent( i ) = -1; priority( i ) = INT_MAX;//(在遍历树中的)父节点，优先级数
            for(j = 0; j < 0; j++){
                if(exist(i, j)) type(i, j) = UNDETERMINED;//类型
            }
        }
    }
public:
//顶点
    int n;//顶点数量
    virtual int insert (Tv const& ) = 0;//插入顶点，返回编号
    virtual Tv remove( int ) = 0; //删除顶点及其关联边，返回该顶点信息
    virtual Tv& vertex( int ) = 0;//顶点v的数据
    virtual int inDegree (int ) = 0;//顶点v的入度
    virtual int outDegree (int ) = 0;//顶点v的出度
    virtual int firstNbr ( int ) = 0;//顶点v的首个邻接顶点
    virtual int nextNbr ( int, int ) = 0;//顶点v的（相对于顶点j的）下一邻接顶点
    virtual VStatus& status( int ) = 0;//顶点v的状态
    virtual int& dTime( int ) = 0;//顶点v的时间标签dTime
    virtual int& fTime( int ) = 0;//顶点v的时间标签fTime
    virtual int& parent ( int ) = 0;//顶点v在遍历树中的父亲
    virtual int& priority ( int ) = 0;//顶点v在遍历树中的优先级数
//边：这里约定，无向边均统一转化为方向互逆的一对有向边，从而将无向图视作有向图的特例
    int e;//边总数
    virtual bool exists(int, int) = 0;//边(v, u)是否存在
    virtual void insert(Te const&, int, int, int) = 0;//在顶点v和u之间插入权重为w的边e
    virtual Te remove( int, int);//删除顶点v和u之间的边e,返回该边信息
    virtual EType& type(int, int) = 0;//边(v, u)的类型
    virtual Te& edge( int , int) = 0;//边(v, u)的数据(该边的确存在)
    virtual int& weight( int, int ) = 0;//边(v, u)的权重
    
// 算法
    void bfs( int ); // 广度优先算法
    void dfs (int ); //深度优先算法
    void bcc (int ); //基于DFS的双连通分量分解算法
} 