//#include<vector>
//#include<iostream>
//using namespace std;
//void bignum_add(vector<int> &rs,vector<int> &l1,vector<int> &l2)
//{
//    // 模拟加和过程
//    // 默认l1 要比 l2 长度小
//    if(l2.size()<l1.size()) bignum_add(rs,l2,l1);
//    int t=0;
//    // 默认 0 1 2 3 4
//    //  低位数 高位数
//    for(int i=0;i<l2.size();i++)
//    {
//        t+=l2[i];
//        if(i<l1.size()) t+=l1[i];
//        rs.push_back(t%10);
//        t/=10; // 保留了上一位
//    }
//    if(t) rs.push_back(t%10);
//}
//// 需要满足 l2>=l1
//void bignum_sub(vector<int> &rs,vector<int> &l1,vector<int> &l2)
//{
//    //
//    int t=0;
//    for(int i=0;i<l2.size();i++)
//    {
//        t=l2[i]-t;
//        if(i<l1.size()) t-=l1[i];
//        rs.push_back((t+10)%10);
//        // t<0 需要加上10
//        // t>=0 不需要管
//        // 通过 (t+10)%10  就合二为一了
//        // 决定是否借位
//        if(t<0) t=1;
//        else t=0;
//    }
//    while(rs.size()>1&&rs.back()==0) rs.pop_back();
//}
//
//// 123
//// 264
//// 将b与l1的每一位相乘
//int cmp(vector<int> &l1,vector<int> &l2)
//{
//    if(l1.size()>l2.size())
//    {
//        return 1;
//    }
//    else if(l1.size()<l2.size())
//    {
//        return 0;
//    }
//    else
//    {
//        int i=l2.size()-1;
//        while(l2[i]==l1[i])
//        {
//            i--;
//        }
//        // 相等无所谓
//
//        return i<0?0:l1[i]>l2[i];
//    }
//
//}
//void bignum_mul(vector<int> &rs,vector<int> &l1,int b)
//{
//
//    int t=0;
//    for(int i=0;i<l1.size();i++)
//    {
//        t+=l1[i]*b;
//        rs.push_back(t%10);
//        t/=10;
//    }
//    if(t) rs.push_back(t%10);
//    while(rs.size()>1&&rs.back()==0) rs.pop_back();
//}
//
//void bignum_div(vector<int>& rs,vector<int> &l1,int b)
//{
//    int t=0;
//    for(int i=l1.size()-1;i>=0;i--)
//    {
//        t=t*10+l1[i];
//        rs.push_back(t/b);
//        t%=b;
//    }
//    reverse(rs.begin(),rs.end());
//    while(rs.size()>1&&rs.back()==0) rs.pop_back();
//}
//
//int main()
//{
//    vector<int> l1{1,2,1}; // 321
//    vector<int> l2{0,2,1}; // 462
//    // 148302
//
//    // 12783
//    vector<int> rs;
//    bignum_div(rs,l1,10);
//
//    for(int i=rs.size()-1;i>=0;i--)
//    {
//        cout<<rs[i];
//    }
//}
//void bignum_add(vector<int> & rs,vector<int> &l1,vector<int> &l2)
//{
//    if(l1.size()<l2.size()) bignum_add(rs,l2,l1);
//    else
//    {
//        int t=0;
//        for(int i=0;i<l1.size();i++)
//        {
//            t+=l1[i];
//            if(i<l2.size()) t+=l2[i];
//            rs.push_back(t%10);
//            t/=10;
//        }
//        if(t) rs.push_back(t%10);
//        while(rs.size()>1&&rs.back()==0) rs.pop_back();
//    }
//
//}
#include<vector>
#include<iostream>
using namespace std;
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