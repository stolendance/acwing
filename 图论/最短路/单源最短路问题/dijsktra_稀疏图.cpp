#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
int dijsktra(vector<vector<Edge> > &graph,int k)
{
    vector<ll> dis(graph.size(),INT_MAX);
    vector<int> st(graph.size(),0);
    priority_queue<pll,vector<pll>,greater<pll> > ls;
    ls.push(pll(0,k));
    dis[k]=0;
    while(ls.size())
    {
        auto item=ls.top();
        ls.pop();
        ll distance=item.first;
        int id=item.second;
        // 保证未加入
        if(st[id]) continue;
        // 加入
        st[id]=1;
        // 扩展更新
        for(int i=0;i<graph[id].size();i++)
        {
            // k->id->id2
            //  distance distance2

            int id2=graph[id][i].next;
            int distance2=graph[id][i].val;
            if(distance+distance2<dis[id2])
            {
                dis[id2]=distance+distance2;
                // 加入队列
                ls.push(pll(dis[id2],id2));
            }
        }
    }
    return (int)*max_element(dis.begin()+1,dis.end());

}
int main()
{
    int n=4;
    int m=3;
    //vector<vector<int> > times={{2,1,1},{2,3,1},{3,4,1}};
    vector<vector<Edge> > graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(Edge(b,c));
    }
    int rs= dijsktra(graph,2);
    cout<<rs<<endl;
}