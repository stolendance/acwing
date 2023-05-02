#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
// https://www.acwing.com/problem/content/849/
struct Edge
{
    int next;
    int value;
    Edge(int next_,int value_):next(next_),value(value_){;}
};
void bfs(vector<vector<Edge> > &graph,vector<int> &vis)
{
    queue<int> ls;
    ls.push(1);
    vis[1]=1;
    while(ls.size()!=0)
    {
        int t=ls.front();
        ls.pop();
        cout<<t<<endl;
        for(int i=0;i<graph[t].size();i++)
        {
            if(vis[graph[t][i].next]==0)
            {
                ls.push(graph[t][i].next);
                vis[graph[t][i].next]=1;
            }
        }
    }
}

int main()
{
    int n=0,m=0;
    cin>>n>>m;
    vector<vector<Edge> > graph(n+1);
    vector<int> vis(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(Edge(b,1));
    }
    bfs(graph,vis);
}