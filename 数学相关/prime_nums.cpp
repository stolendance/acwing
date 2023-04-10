#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void prime_nums(int n,vector<int> &primes)
{
    vector<int> st(n,0);
    // primes 存储所有素数
    // st[x]存储x是否被筛掉
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) primes.push_back(i);
        for(int j=i+i;j<=n;j+=i)
        {
            st[j]=1;
        }
    }
}
int main()
{
    vector<int> primes;
    prime_nums(10,primes);
    for(int i=0;i<primes.size();i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<endl;
}