// minimized maximum pair sum in array
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int minPairSum(vector<int> &nums){
    int n=nums.size();
    int i=0;
    int j=n-1;
    int ans=0;
    sort(begin(nums),end(nums));
    while (i<=j)
    {
        int result = nums[i] + nums[j];
        ans = max(ans,result);
        i++;
        j--;
        
    }

    cout << ans << endl;
    return ans;
}
int main(){
    vector<int>nums = { 3,5,4,2,4,6};

    return minPairSum(nums);
}