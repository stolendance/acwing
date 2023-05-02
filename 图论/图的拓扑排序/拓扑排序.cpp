#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//https://www.acwing.com/problem/content/850/
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
void topological_order(vector<vector<Edge> >& graph,vector<int> &in)
{
    queue<int> ls;
    vector<int> vis(graph.size()+1);
    vector<int> rs;
    for(int i=1;i<in.size();i++)
    {
        if(in[i]==0)
        {
            ls.push(i);
        }
    }
    while(ls.size()!=0)
    {
        int t=ls.front();
        vis[t]=1;
        rs.push_back(t);
        ls.pop();
        for(int j=0;j<graph[t].size();j++)
        {
            if(vis[graph[t][j].next]==0)
            {
                // 删除t->graph[t][j].next
                in[graph[t][j].next]-=1;
                if(in[graph[t][j].next]==0)
                {
                    ls.push(graph[t][j].next);
                }
            }
        }
    }
    if(rs.size()==graph.size()-1)
    {
        for(int i=0;i<rs.size();i++)
        {
            cout<<rs[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<Edge> > graph(n+1);
    vector<int> in(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        //a->b
        graph[a].push_back(Edge(b,1));
        in[b]+=1;
    }
    topological_order(graph,in);

}