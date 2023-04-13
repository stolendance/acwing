#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int> pii;

// 题目地址： https://www.acwing.com/problem/content/804/
int main()
{
    int n=0;
    int m=0;
    cin>>n>>m;
    vector<pii> add;
    vector<pii> query;
    vector<int> alls;
    for(int i=0;i<n;i++)
    {
        int a=0;
        int b=0;
        cin>>a>>b;
        add.push_back({a,b});
        alls.push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        int a=0;
        int b=0;
        cin>>a>>b;
        query.push_back({a,b});
        alls.push_back(a);
        alls.push_back(b);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    vector<int> s(alls.size());

    // 左闭右闭
    // 加

    for(int i=0;i<add.size();i++)
    {
        auto item=add[i];
        int k= lower_bound(alls.begin(),alls.end(),item.first)-alls.begin();
        s[k]+=item.second;
    }

    // 前缀和数组 [i,j] 左闭右闭
    for(int i=1;i<s.size();i++) s[i]+=s[i-1];
    for(int i=0;i<m;i++)
    {
        auto item=query[i];
        int k1= lower_bound(alls.begin(),alls.end(),item.first)-alls.begin();
        int k2= lower_bound(alls.begin(),alls.end(),item.second)-alls.begin();
        cout<<s[k2]-((k1>=1)?s[k1-1]:0) <<endl;
    }


}