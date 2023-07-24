// 写出从图的邻接表表示转化为邻接矩阵表示的算法

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
#define  MaxNum 20                 //图的最大顶点数
#define MaxValue 65535			   //最大值
// 定义边表结点
struct ArcNode
{
    int adjvex;                   // 邻接点域
    ArcNode* next;                 //下一个邻接点 
};
struct Graph
{
	struct  ArcNode* VertexNode[MaxNum];     //定义顶点表结点
	int VertextNum;                //顶点数量
	int EdgeNum;                   //边的数量 
	int Edge[MaxNum][MaxNum];      //邻接矩阵 
};
void outAdjacency(Graph GM){        //输出邻接表 
	
	for(int i=1;i<=GM.VertextNum;i++){//定义顶点表结点
	   
	    ArcNode* B = new ArcNode;
	    B= GM.VertexNode[i];
	    cout << B->adjvex;
		B = B->next; 
	    while(B!=nullptr){
	    	cout << "->"<<B->adjvex;
	    	B = B->next;	    	
		}
		cout << "->Null"<<endl;
	}
}
void adjacency_matrix(Graph GM){        //输出邻接矩阵 
 
	for(int i=1;i<=GM.VertextNum;i++){//定义顶点表结点
	    ArcNode* B = new ArcNode;
	    B= GM.VertexNode[i];
		B = B->next; 
	    while(B!=nullptr){
	    	GM.Edge[i][B->adjvex]=1;
	    	B = B->next;	    	
		}
	}
	for(int i=1;i<=GM.VertextNum;i++){    //打印邻接矩阵 
		for(int j=1;j<=GM.VertextNum;j++){
			  cout << GM.Edge[i][j] << " ";
		}
		cout << endl;
	}
}
int main(){	
	Graph GM;                     //初始化图
	cin>>GM.VertextNum;           //输入顶点数量
	cin>>GM.EdgeNum;              //入边的数量
	for(int i=1;i<=GM.VertextNum;i++){//定义顶点表结点
	    ArcNode* A = new ArcNode;
		A->adjvex=i;
		A->next=nullptr;
		GM.VertexNode[i]=A;
	}
	for(int i=1;i<=GM.EdgeNum;i++){
		int j,k;
		cin >>j >>k ;
		ArcNode* A = new ArcNode;
		A->adjvex=k;
		A->next=GM.VertexNode[j]->next;
		GM.VertexNode[j]->next = A;
	}
	for(int i=1;i<=GM.VertextNum;i++){    //初始化邻接矩阵 为0； 
		for(int j=1;j<=GM.VertextNum;j++){
			  GM.Edge[i][j]=0; 
		}
	}
	cout << "输出邻接表"<<endl;	
	outAdjacency(GM);              //输出邻接表
	cout << "输出邻接矩阵"<<endl;
	adjacency_matrix(GM);         //输出邻接矩阵
	return 0;
}