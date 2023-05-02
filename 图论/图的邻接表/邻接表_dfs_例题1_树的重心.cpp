// 邻接表
// 深度遍历
// 树的重心
//
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
int res_rs=INT_MAX;
int dfs(vector<int> &vis,vector<vector<Edge> >& graph,int u)
{
    vis[u]=1;
    int res=0;
    int sum=1;
    // 记得：来的路不会再走了
    for(int i=0;i<graph[u].size();i++)
    {
        if(vis[graph[u][i].next]==0)
        {
            int num=dfs(vis,graph,graph[u][i].next);
            res=max(res,num);
            sum+=num;
        }
    }
    // 还需要考虑 来的时候的块
    int temp= graph.size()-sum;
    res=max(res,temp);
    if(res<res_rs)
    {
        res_rs=res;
    }
    return sum;
}
int main()
{
    int n=0;
    cin>>n;
    vector<vector<Edge> > graph(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a=0;
        cin>>a;
        int b=0;
        cin>>b;
        // 无向
        // a->b b->a
        graph[a].push_back(Edge(b,1));
        graph[b].push_back(Edge(a,1));
    }
    vector<int> vis(n+1);
    dfs(vis,graph,1);
    cout<<res_rs<<endl;

}