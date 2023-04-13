#include<iostream>
#include<vector>
using namespace std;

// 1001000  求的 1000
int lowbit(int x)
{
    return x&-x;
}
// 1001000 从0位开始 求k位的数
int k_bit(int x,int k)
{
    return x>>k&1;
}
int main()
{
    //两个基本位运算的基本操作

}