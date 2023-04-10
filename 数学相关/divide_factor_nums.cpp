#include<iostream>
#include<algorithm>
using namespace std;
int divide_factor_nums(int n)
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
        ans*=(s+1);
    }
    if(n>1)  ans*=2;
    return ans;
}
int main()
{
    // 1 2
    // 1 5 
    // 1 2 5 10
    cout<<divide_factor_nums(10)<<endl;
}