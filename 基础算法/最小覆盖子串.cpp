#include<iostream>
#include<vector>
#include<map>
using namespace std;
// 滑动窗口
// https://leetcode.cn/problems/minimum-window-substring/ 最后一个用例没过  不管了
bool isin(map<char,int> &has,map<char,int> &target)
{
    for(auto item:target)
    {
        if(has.count(item.first))
        {
            if(has[item.first]<item.second)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
string minWindow(string s, string t) {
    string ans="";
    int l=0,r=0;
    map<char,int> target;
    for(char t1:t)
    {
        if(target.count(t1))
        {
            target[t1]+=1;
        }
        else
        {
            target[t1]=1;
        }
    }

    map<char,int> has;
    while(r<s.size())
    {

        if(has.count(s[r]))
        {
            has[s[r]]+=1;
        }
        else
        {
            has[s[r]]=1;
        }
        r+=1;
        while(l<=r&&isin(has,target))
        {
            if(ans.size()==0||r-l<ans.size())
            {
                ans=s.substr(l,r-l);
            }
            if(has.count(s[l]))
            {
                has[s[l]]-=1;
            }
            l+=1;
        }
        //[l,r) 是要的字符串
    }
    cout<<ans<<endl;
    return ans;
}
int main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    minWindow(s,t);
}