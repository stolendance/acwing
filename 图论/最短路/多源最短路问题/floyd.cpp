#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
void floyd(vector<vector<ll> > &graph)
{
    for(int k=1;k<graph.size();k++)
    {
        for(int i=1;i<graph.size();i++)
        {
            for(int j=1;j<graph.size();j++)
            {
                if(graph[i][k]!=INT_MAX&&graph[k][j]!=INT_MAX)
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }

}
int main()
{
    cout<<INT_MAX<<endl;
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll> > graph(n+1, vector<ll>(n+1,INT_MAX));
    for(int i=1;i<graph.size();i++) graph[i][i]=0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b],(ll)c);
    }

    floyd(graph);
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        if(graph[a][b]==INT_MAX)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<graph[a][b]<<endl;
        }
    }

}