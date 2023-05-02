#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
typedef long long ll;
int prim(vector<vector<ll> >& graph)
{
    vector<ll> dis(graph.size(),INT_MAX);
    vector<int> st(graph.size(),0);
    int res=0;
    for(int i=1;i<graph.size();i++)
    {

        // 选点
        int id=1;
        int minx=INT_MAX;
        for(int j=1;j<dis.size();j++)
        {
            if(st[j]==0&&dis[j]<minx)
            {
                id=j;
                minx=dis[j];
            }
        }
        // 更新
        // 默认第一个点 加入 1
        if(i!=1&&minx==INT_MAX) return INT_MAX;
        if(i!=1) res+=minx; //第一个点不需要距离
        for(int j=1;j<dis.size();j++)
        {
            dis[j]=min(dis[j],graph[id][j]);
        }
        st[id]=1;
    }

    return res;
}
int main()
{
    cout<<INT_MAX<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<ll> > graph(n+1, vector<ll>(n+1,INT_MAX));
    for(int i=1;i<n+1;i++) graph[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b],(ll)c);
        graph[b][a]=min(graph[b][a],(ll)c);
    }
    int t=prim(graph);

    if(t==INT_MAX) cout<<"impossible"<<endl;
    else cout<<t<<endl;
}