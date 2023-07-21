// 从顺序表中删除具有最小值的元素(假设唯一) 并由函数返回被删元素的值。
// 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

typedef struct{
    int data[N];
    int length;
}SqList;

int n,e;

bool delete_min_element(SqList &L,int &e){
    if(L.length==0) return false;
    e=L.data[0];
    int min_pos;
    for(int i=0;i<L.length;i++){
        if(L.data[i]<e){
            e=L.data[i];
            min_pos=i;
        }
    }
    L.data[min_pos]=L.data[L.length-1];
	L.length--;
	return true;
}

int main(){
    SqList L;
    cin>>n;
    for(int i=0;i<n;i++) cin>>L.data[i];
    L.length=n;
    if(delete_min_element(L,e)){
        cout<<e<<endl;
        for(int i=0;i<L.length;i++) cout<<L.data[i]<<" ";
    }
    else cout<<"error"<<endl;
    return 0;
}