#include<iostream>
#include<algorithm>
using namespace std;

bool is_prime(int n)
{
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    cout<<is_prime(4)<<endl;
}