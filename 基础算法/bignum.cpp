
#include<vector>
#include<iostream>
using namespace std;

// 题目地址：
// https://www.acwing.com/problem/content/793/
// https://www.acwing.com/problem/content/794/
// https://www.acwing.com/problem/content/795/
// https://www.acwing.com/problem/content/796/
void bignum_add(vector<int> & rs,vector<int> &l1,vector<int> &l2)
{
    if(l1.size()<l2.size()) bignum_add(rs,l2,l1);
    else
    {
        int t=0;
        for(int i=0;i<l1.size();i++)
        {
            t+=l1[i];
            if(i<l2.size()) t+=l2[i];
            rs.push_back(t%10);
            t/=10;
        }
        if(t) rs.push_back(t%10);
        while(rs.size()>1&&rs.back()==0) rs.pop_back();
    }
}
int cmp(vector<int> &l1,vector<int> &l2)
{
    if(l1.size()>l2.size())
    {
        return 1;
    }
    else if(l2.size()>l1.size())
    {
        return 0;
    }
    else
    {
        int i=l1.size()-1;// 从高位开始对比
        while(l1[i]==l2[i])
        {
            i--;
        }
        return i<0?1:l1[i]>l2[i];// 相等返回1 否则会出现-0
    }
}
void bignum_del(vector<int> &rs,vector<int> &l1,vector<int> &l2)
{
    int t=0;
    for(int i=0;i<l1.size();i++)
    {
        t=l1[i]-t;
        if(i<l2.size()) t-=l2[i];
        rs.push_back((t+10)%10);
        if(t<0) t=1;
        else t=0;
    }
    while(rs.size()>1&&rs.back()==0) rs.pop_back();
}
void bignum_mul(vector<int> &rs,vector<int> &l1,int b)
{
    int t=0;
    // 123 * 4
    //    2
    for(int i=0;i<l1.size()||t;i++)
    {
        if(i<l1.size()) t+=l1[i]*b;
        rs.push_back(t%10);
        t/=10;
    }
    while(rs.size()>1&&rs.back()==0) rs.pop_back();
}
int bignum_div(vector<int> &rs,vector<int> &l1,int b)
{
    int t=0;
    for(int i=l1.size()-1;i>=0;i--)
    {
        t=t*10+l1[i];
        rs.push_back(t/b);
        t%=b;
    }
    reverse(rs.begin(),rs.end());
    while(rs.size()>1&&rs.back()==0) rs.pop_back();
    return t;
}
int main()
{
    string s1;
    cin>>s1;
    int b=0;
    cin>>b;
    vector<int> l1;
    for(int i=s1.size()-1;i>=0;i--)
    {
        l1.push_back(s1[i]-'0');
    }
    vector<int> rs;
    int t=bignum_div(rs,l1,b);
    for(int i=rs.size()-1;i>=0;i--)
    {
        cout<<rs[i];
    }
    cout<<endl;
    cout<<t;

}