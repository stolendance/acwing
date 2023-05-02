#include<iostream>
#include<vector>
using namespace std;
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
int main()
{
    int N=10;// 10个节点
    vector<vector<Edge> > vec(N);

    // 加入一条 5->2 的边,权重为8
    vec[5].push_back(Edge(2,8));




}