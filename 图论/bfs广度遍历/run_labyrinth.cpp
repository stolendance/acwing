#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
int bfs(vector<vector<int> > &mapit)
{
    int n=mapit.size();
    int m=mapit[0].size();
    queue<pair<int,int> > ls;
    vector<vector<int> > dis(n,vector<int>(m));
    vector<vector<int> > vis(n,vector<int>(m));
    ls.push(make_pair(0,0));
    while(ls.size()!=0)
    {
        pair<int,int> it=ls.front();
        ls.pop();
        int qs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<4;i++)
        {
            if(it.first+qs[i][0]<n&&it.first+qs[i][0]>=0&&it.second+qs[i][1]<m&&it.second+qs[i][1]>=0&&vis[it.first+qs[i][0]][it.second+qs[i][1]]==0&&mapit[it.first+qs[i][0]][it.second+qs[i][1]]==0)
            {
                dis[it.first+qs[i][0]][it.second+qs[i][1]]=dis[it.first][it.second]+1;
                vis[it.first+qs[i][0]][it.second+qs[i][1]]=1;
                ls.push(make_pair(it.first+qs[i][0],it.second+qs[i][1]));
            }
        }
    }
    return dis[n-1][m-1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > mapit(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mapit[i][j];
        }
    }
    cout<<bfs(mapit)<<endl;

}