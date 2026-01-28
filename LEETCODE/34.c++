#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            ans.push_back(i);
        }
    }

    if (ans.size() == 0)
    {
        return {-1, -1};
    }
    // cout << ans.size();
    for(int j=0;j<ans.size();j++){
        cout<< ans[j];
    }
    // sirf first aur last index chahiye
    return {ans.front(), ans.back()};
}

int main(){
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;
    searchRange(nums,target);
    return 0;
}