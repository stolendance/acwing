#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
using namespace std;


void dfs(map<int,int> &kv,map<int,int> &kv2,map<int,int> &kv3,vector<map<int,int> > &rss,int k,int n)
{
    if(kv.size()==n)
    {
        rss.push_back(kv);
    }
    for(int i=0;i<n;i++) // 在第k行选择哪一列
    {
        if(kv.count(i))
        {
            continue;
        }
        if(kv2.count(k+i))
        {
            continue;
        }
        if(kv3.count(k-i))
        {
            continue;
        }
        kv[i]=k;
        kv2[k+i]=1;
        kv3[k-i]=1;
        dfs(kv,kv2,kv3,rss,k+1,n);
        kv.erase(i);
        kv2.erase(k+i);
        kv3.erase(k-i);
    }
}

int main()
{
    int n=0;
    cin>>n;
    map<int,int> kv;// key 是列，value是行
    map<int,int> kv2;// 存储第一种截距 +
    map<int,int> kv3;// 存储第二种截距 -
    vector<map<int,int> > rss;
    dfs(kv,kv2,kv3,rss,0,n);
    for(auto item:rss)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(item.count(j)&&item[j]==i)
                {
                    cout<<"Q";
                }
                else
                {
                    cout<<".";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

}