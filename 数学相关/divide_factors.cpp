#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void divide_factors(int n,vector<int> &rs)
{
    for(int i=1;i<=n/i;i++)
    {
        if(n%i==0) 
        {
            rs.push_back(i);
            if(i!=(n/i)) rs.push_back(n/i);
        }    
    }
    sort(rs.begin(),rs.end());
}
int main()
{
    vector<int> rs;
    divide_factors(10,rs);
    for(int i=0;i<rs.size();i++)
    {
        cout<<rs[i]<<" ";
    }
    cout<<endl;
}