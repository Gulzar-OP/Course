#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int removeDuplicates(vector<int> &nums){
    int n = nums.size();
    if (n <= 2)
        return n;

    int i = 1;     
    int count = 1; 
    for (int j = 1; j < n; j++){
        if (nums[j] == nums[j - 1]){
            count++;
        }
        else{
            count = 1;
        }
        if (count <= 2){
            nums[i] = nums[j];
            i++;
        }
    }
    return i; // new length
}

int main()
{
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    removeDuplicates(nums);
    return 0;
}