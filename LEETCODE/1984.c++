#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minimumDifference(vector<int> &nums, int k){
    int n = nums.size();
    int minPossible=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i;j<=k;j++){
            int diff = nums[i] - nums[j];
        }
        
    }
}
int main(){
    vector<int> nums = [ 9, 4, 1, 7 ];
    int k = 2
     
    minimumDifference(nums, k);

    return 0;
}