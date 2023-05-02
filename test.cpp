#include<iostream>
#include<vector>
using namespace std;
typedef long long cainiaosb;
cainiaosb minx=2540;
cainiaosb maxx=2630;
cainiaosb num[3];
void dfs(cainiaosb ls,vector<cainiaosb>&temp,vector<cainiaosb>&rs,vector<vector<cainiaosb> > &rss)
{
    if(temp.size()==3)
    {
        if(ls>minx&&ls<maxx)
        {
            rss.push_back(temp);
            rs.push_back(ls);
        }
        return;
    }
    for(int i=-5;i<=5;i++)
    {
        temp.push_back(i);
        dfs(ls+i*num[temp.size()-1],temp,rs,rss);
        temp.pop_back();
    }
}
int main()
{
    cin>>num[0]>>num[1]>>num[2];
    vector<cainiaosb> rs;
    vector<vector<cainiaosb> > rss;
    vector<cainiaosb> temp;
    dfs(0,temp,rs,rss);
    for(int i=0;i<rs.size();i++)
    {
        cout<<rs[i]<<" ";
        for(int j=0;j<rss[i].size();j++)
        {
            cout<<rss[i][j]<<" ";
        }
        cout<<endl;
    }
}