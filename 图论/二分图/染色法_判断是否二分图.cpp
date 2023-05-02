#include<iostream>
#include<vector>
using namespace std;
struct Edge{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
bool dfs(vector<vector<Edge> > &graph,vector<int> &colors,int i,int c)
{
    colors[i]=c;
    for(int j=0;j< graph[i].size();j++)
    {
        int next=graph[i][j].next;
        if(colors[next]==0)
        {
            if(!dfs(graph,colors,next,3-c))
                return false;
        }
        else
        {
            if(colors[next]==c) return false;
        }
    }
    return true;
}
bool paint2(vector<vector<Edge> > &graph)
{
    vector<int> colors(graph.size(),0);
    for(int i=1;i<graph.size();i++)
    {
        if(colors[i]==0)
        {
           bool rs=dfs(graph,colors,i,1);
           if(!rs)
           {
               return false;
           }
        }
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<Edge> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(Edge(b,0));
        graph[b].push_back(Edge(a,0));
    }
    if(paint2(graph))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}

