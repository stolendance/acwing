#include<iostream>
using namespace std;
int prime_n_num(int n)
{
    int ans=n;
    for(int i=2;i<=n/i;i++)
    {
        int s=0;
        while(n%i==0)
        {
            s+=1;
            n/=i;
        }
        ans=(ans-ans/i);
    }
    if(n>1) ans=(ans-ans/n);
    return ans;
}
int main()
{
    // 1 2 3 4 5 
   cout<<prime_n_num(6)<<endl;
}