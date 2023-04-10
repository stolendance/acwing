#include<iostream>
using namespace std;
typedef long long ll;
int quick_mi(int a,int k,int p)
{
    // 先将k转化为2进制,不断地处理最后一位
    ll res=1;
    // 比如 4^5mod10
    // 4-> 100
    // 预处理 求出 4^(2^0) 4^(2^1) 4^(2^log(5))
    // a =4mod10 16mod10 不断是前面的平方mod10 当k位处理完后，自然到log5
    // 最后把1位 的乘起来即可
    while(k)
    {
        if(k&1)
        {
            res*=a%p;
        }
        k>>=1;
        a=a*a%p;
    }
    return res;

}
int main()
{
    cout<<quick_mi(4,5,10)<<endl;
}