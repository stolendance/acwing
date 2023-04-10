#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    cout<<"b:"<<b<<"a:"<<a<<endl;
    return b?gcd(b,a%b):a;
}
int main()
{
    cout<<gcd(5,10)<<endl;
    


}