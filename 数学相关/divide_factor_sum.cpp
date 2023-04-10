#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int divide_factor_sum(int n)
{
    int ans=1;
    for(int i=2;i<=n/i;i++)
    {
        int s=0;
        while(n%i==0)
        {
            n/=i;
            s+=1;
        }
        int sums=0;
        for(int j=0;j<=s;j++)
        {
            sums+=pow(i,j);
        }
        ans*=sums;
    }
    if(n>1) 
    {
        ans*=pow(n,1)+1;
    }
    return ans;
}
int main()
{
    int n=10;
    // n=10 1+2+5+10=18
    cout<<divide_factor_sum(n)<<endl;
}