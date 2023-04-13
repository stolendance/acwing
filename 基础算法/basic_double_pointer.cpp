#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
// 分开一个字符串，分成很多单词
void split_word(string s)
{
    int l=0,r=0;
    while(r<s.size())
    {
        window+;
        r++;
        while(!check(window))
        {
            l++;
        }

    }
}

bool check(map<int,int> &temp)
{
    for(auto item:temp)
    {
        if(item.second>=2)
        {
            return false;
        }
    }
    return true;
}

void max_length_unique_num(vector<int> &nums)
{
    int l=0,r=0;
    map<int,int> temp;
    int ans=0;
    while(r<nums.size())
    {
        // 增大窗口
        if(temp.count(nums[r]))
        {
            temp[nums[r]]+=1;
        }
        else
        {
            temp[nums[r]]=1;
        }
        r+=1;
        while(!check(temp))
        {
            // 缩小窗口
            if(temp.count(nums[l]))
            {
                temp[nums[l]]-=1;
            }
            l+=1;
        }
        ans=max(ans,r-l);
    }
    cout<<ans<<endl;


}
int main()
{
    //               0 1 2 3 4
    vector<int> temp{1,2,2,3,5};
    max_length_unique_num(temp);
}