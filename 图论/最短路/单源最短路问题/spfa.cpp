#include<map>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
int spfa(vector<vector<Edge> > graph,int k)
{
    vector<ll> dis(graph.size(),INT_MAX);
    vector<int> isin(graph.size(),0);
    queue<int> ls;
    ls.push(k);
    dis[k]=0;
    isin[k]=1;
    while(ls.size())
    {
        int t=ls.front();
        ls.pop();
        isin[t]=0;
        for(int i=0;i<graph[t].size();i++)
        {
            // k->t->id
            int distance=graph[t][i].val;
            int id=graph[t][i].next;
            if(dis[t]+distance<dis[id]){
                dis[id]=dis[t]+distance;
                if(isin[id]==0)
                {
                    ls.push(id);
                    isin[id]=1;
                }
            }

        }
    }
    int rs= *max_element(dis.begin()+1,dis.end());
    if(rs==INT_MAX) return -1;
    else return rs;
}
int main()
{
    int n=4;
    int m=3;
    cin>>n>>m;
    //vector<vector<int> > times={{2,1,1},{2,3,1},{3,4,1}};
    vector<vector<Edge> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(Edge(b,c));
    }
    int rs= spfa(graph,2);
    cout<<rs<<endl;
}