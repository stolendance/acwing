
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int group_bag(int n,int b,vector<vector<int> >& w,vector<vector<int> >& v)
{
    vector<vector<int> > dp(n+1, vector<int>(b+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=b;j++)
        {
            dp[i][j]=dp[i][j-1];
            for(int l=0;l<v[i].size();l++)
            {
                if(w[i][l]<=j) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i][l]]+v[i][l]);
            }
        }
    }
    return dp[n][b];
}
int main()
{
    vector<vector<int> > w;
    vector<vector<int> > v;
    int n=0;
    int b=0;
    cin>>n>>b;
    w.push_back(vector<int>(1));
    v.push_back(vector<int>(1));
    for(int i=1;i<=n;i++)
    {
        int n1=0;
        cin>>n1;
        vector<int> v1(n1);
        vector<int> w1(n1);
        for(int j=0;j<n1;j++)
        {
            int a=0;
            int b=0;
            cin>>a>>b;
            w1.push_back(a);
            v1.push_back(b);
        }
        w.push_back(w1);
        v.push_back(v1);
    }
    cout<<group_bag(n,b,w,v)<<endl;
}