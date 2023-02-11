#include "../chapter_2/vector.h"
#include "graph.h"

template <typename Tv> struct Vertex{
    Tv data;//数据
    int inDegree, outDegree;//入度、出度
    VStatus status;//状态
    int dTime, fTime;
    int parent; int priority;
    Vertex( Tv const& d = (Tv) 0) :
        data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
        dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}//暂不考虑权重溢出

};

template <typename Te> struct Edge{
    Te data;//数据
    int weight;//权重
    EType type;//类型
    Edge( Te const& d, int w) : data(d), weight(w) type(UNDETERMINED) {}
};

template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te>{//基于向量 以邻接矩阵的形式实现的图
private:
    Vector< Vertex<Tv> > V;//顶点集
    Vector< Vector< Edge<Te>* > > E;//边集(邻接矩阵，以指针形式创建)
public:
    GraphMatrix(){ n = e = 0;}
    ~GraphMatrix(){
        for(int j = 0; j < n; j++){//所有动态创建的
            for (k = 0; k < n; k++){//边记录
                delete E[j][k];//逐条删除
            }
        }
    }

//顶点的基本操作:查询的第i个顶点(0 <= i < n)
    virtual Tv& vertex( int i) {return V[i].data;}//数据
    virtual int inDegree( int i) {return V[i].inDegree;}
    virtual int outDegree( int i) {return V[i].outDEegree;}
    virtual int firstNbr(int i) {return nextNbr(i, n);}//首个邻接顶点, 即V[n-1]
    virtual int nextNbr(int i, int j) 
    { while (-1 < j && (!exist(i, --j) )) return j;}//逆向线性试探
    virtual int& dTime(int i) {return V[i].dTime;}
    virtual int& fTime(int i) {return V[i].fTime;}
    virtual int& parent(int i) {return V[i].parent;}
    virtual int& priority(int i) {return V[i].priority;}

//顶点的动态操作
    virtual int insert (Tv const& vertex ){
        for(j = 0; j < nl j++) { E[j].insert(NULL);}//E[j]为Vector，可以借用Vector的insert算法，给各顶点预留一条潜在边
        n++;
        E.insert(Vector<Edge<Te>*> (n, n , (Edge<Te>*) NULL));//创建新顶点对应的边向量
        return V.insert(Vertex<Tv> (vertex));//顶点向量增加一个顶点
    }   
    virtual Tv remove(int i){
        for (int j = 0; j < n; j++){//所有出边
            if (exist(i, j)) { delete E[i][j]; E[j].inDegree--;}//逐条删除
        }
        E.remove(i); n--;//删除第i行
        Tv vBak = V[i]; V.remove(i);//删除顶点i
        for (int j = 0; j < n; j++){//所有入边
            if( Edge<Te>* e = E[j].remove(i)) { delete e; V[j].outDegree--;}//逐条删除
        }
        return vBak;
    }


//边的确认操作
    virtual bool exist(int i, int j)//边(i, j)是否存在
    { return (0 <= i < n) && (0 <= j < n) && E[i][j] != NULL;}
//边的基本操作
    virtual EType& type(int i, int j) { return E[i][j]->type;}
    virtual int& weight( int i, int j) {return E[i][j]->weight;}
    virtual Te& edge(int i, int j) {return E[i][j]->data;}
//边的动态操作
    //插入权重为w的边e=(i, j)
    virtual void insert (Te const& edge, int w, int i, int j){
        if(exist(i, j)) return;//确保该边不存在
        E[i][j] = new Edge(edge, w);//创建新边
        e++; V[i].outDegree++; V[j].inDegree++;//更新边计数与关联顶点的度数
    }
    virtual Te remove(int i, int j){
        Te eBak = E[i][j];//备份
        delete E[i][j];//删除
        E[i][j] = NULL;//置空指针，防止野指针的出现
        e--; V[i].outDegree--; V[j].inDegree--;
        return eBak;
    }

}