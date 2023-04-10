#include<iostream>
#include<algorithm>
using namespace std;
void divide_prime(int n)
{
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0) 
        {
            int s=0;
            while(n%i==0)
            {
                n/=i;
                s++;
            }
            cout<<s<<":"<<i<<endl;
        }
    }
    if(n>1) cout<<1<<":"<<n<<endl;
}
int main()
{
    divide_prime(24);// 2*2*2*3
}