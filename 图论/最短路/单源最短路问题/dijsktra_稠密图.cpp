#include<iostream>
#include<vector>
using namespace std;
#define INA INT_MAX
//https://leetcode.cn/problems/network-delay-time/

// 稠密图
int networkDelayTime(vector<vector<int> >& times, int N, int k) {
    vector<vector<long long> > graph(N+1,vector<long long>(N+1,INT_MAX));
    for(int i=1;i<=N;i++)    graph[i][i]=0;
    for(auto e:times)    graph[e[0]][e[1]]=e[2];

    vector<int> vis(graph.size(),0);
    vis[k]=1;
    for(int i=1;i<graph.size()-1;i++)
    {
        int minid=0,minx=INA;
        // 在没有使用过的检查最短的距离
        for(int j=1;j<graph.size();j++)
        {
            if(vis[j]==0&&graph[k][j]<minx)
            {
                minid=j;
                minx=graph[k][j];
            }
        }
        vis[minid]=1;
        // 更新
        for(int j=1;j<graph.size();j++)
        {
            graph[k][j]=min(graph[k][j],graph[k][minid]+ graph[minid][j]);
        }
    }
    int ans=0;
    for(int i=1;i< graph.size();i++)
    {
        if(graph[k][i]==INT_MAX) return -1;
        ans=max(ans, (int)graph[k][i]);
    }
    return ans;
}
int main()
{

    vector<vector<int> > times={{2,1,1},{2,3,1},{3,4,1}};
    int rs=networkDelayTime(times,4,2);
    cout<<rs<<endl;

}