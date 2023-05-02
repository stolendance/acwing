#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void dfs(string &rs,vector<string> &rss,vector<int> &choose,int n)
{
    if(rs.size()==n)
    {
        rss.push_back(rs);
        return;
    }
    for(int i=0;i<choose.size();i++)
    {
        int temp=choose[i];
        rs.push_back(temp+'0');
        choose.erase(choose.begin()+i);
        dfs(rs,rss,choose,n);
        rs.pop_back();
        choose.insert(choose.begin()+i,temp);
    }
}

int main()
{
    int n=0;
    cin>>n;
    string rs;
    vector<string > rss;
    vector<int> choose;
    for(int i=1;i<=n;i++)
    {
        choose.push_back(i);
    }
    dfs(rs,rss,choose,n);
    sort(rss.begin(),rss.end());
    for(int i=0;i<rss.size();i++)
    {
        cout<<rss[i];
        cout<<endl;
    }
}