#include<iostream>
#include<vector>
using namespace std;
int get_daddy(int x,vector<int> &f) // 并查集 模版
{
    if(x!=f[x])
    {
        f[x]= get_daddy(f[x],f);
    }
    return f[x];
}

struct Edge
{
    int from;
    int next;
    int val;
    Edge(int from_,int next_,int val_):from(from_),next(next_),val(val_){;}
};
bool cmp(Edge l1,Edge l2)
{
    if(l1.val<l2.val)
    {
        return true;
    }
    else
        return false;
}
int kruskal(vector<Edge> &edges,int n)
{
    int res=0;
    int cnt=0;
    sort(edges.begin(),edges.end(),cmp);
    vector<int> f(n+1);
    for(int i=0;i<f.size();i++)
    {
        f[i]=i;
    }
    for(int i=0;i<edges.size();i++)
    {
        int t1=edges[i].from;
        int t2=edges[i].next;
        t1= get_daddy(t1,f);
        t2= get_daddy(t2,f);
        if(t1!=t2)
        {
            cnt+=1;
            res+=edges[i].val;
            f[t1]=t2;
        }
        if(cnt==n-1) return res;
    }
    if(cnt<n-1) return INT_MAX;
    else return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<Edge> edges;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back(Edge(a,b,c));
    }
    int res=kruskal(edges,n);
    if(res==INT_MAX)
        cout<<"impossible"<<endl;
    else
        cout<<res<<endl;
}