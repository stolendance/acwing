#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int bag_01(int n,int b,vector<int>&w,vector<int>&v)
{
    vector<vector<int> > dp(n+1,vector<int>(b+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=b;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    return dp[n][b];
}

int main()
{
    int n_fake=0;
    cin>>n_fake;
    int b=0;
    cin>>b;
    int n=0;
    vector<int> v;
    vector<int> w;
    v.push_back(-1);
    w.push_back(-1);
    for(int i=1;i<=n_fake;i++)
    {
        int l1,l2,l3;
        // l1 是 体积
        // l2 是 价值
        // l3 是 个数
        cin>>l1>>l2>>l3;
        int k=1;
        while(k<=l3)
        {
            l3-=k;
            v.push_back(l2*k);
            w.push_back(l1*k);
            n+=1;
            k*=2;
        }
        if(l3!=0)
        {
            v.push_back(l2*l3);
            w.push_back(l1*l3);
            n+=1;
        }
    }
    cout<<bag_01(n,b,w,v)<<endl;


}