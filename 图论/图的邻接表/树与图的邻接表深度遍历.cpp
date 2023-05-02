#include<iostream>
#include<vector>
using namespace std;
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};

void dfs(vector<int> &vis,vector<vector<Edge> > &vec,int u)
{
    vis[u]=1;
    for(int i=0;i<vec[u].size();i++)
    {
        if(vis[u]==0) dfs(vis,vec,vec[u][i].next);
    }
}
int main()
{
    int N=10;// 10个节点
    vector<vector<Edge> > vec(N);

    // 加入一条 5->2 的边,权重为8
    vec[5].push_back(Edge(2,8));
    vector<int> vis(N);// 代表该点是否访问过
    dfs(vis,vec,0);

}