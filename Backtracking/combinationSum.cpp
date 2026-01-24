#include <iostream>
using namespace std;

class Solution{
public:
    void findCombinations(int idx, vector<int>& candidates,int target,vector<int>&current,vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(current);
        }
        for(int i=idx;i<candidates.size();i++){
            if(candidates[i] <= target){
                // pick element
                current.push_back(candidates[i]);
                // recurse with same index
                findCombinations(i,candidates,target-candidates[i],current,ans);
                // backtrack(remove last elemet)
                current.pop_back();
            }
        }
    }
    vector<vector<int>>combinationSum(vector<int>& candidates,int target){
        vector<vector<int>>ans;
        vector<int>current;
        findCombinations(0,candidates,target,current,ans);
        return ans;
    }

};
    int main()
    {

        Solution sol;
        vector<int> candidates = {2, 3, 6, 7};
        int target = 7;

        vector<vector<int>> result = sol.combinationSum(candidates, target);

        cout << "Combinations are:\n";
        for (auto comb : result)
        {
            cout << "[ ";
            for (int num : comb)
                cout << num << " ";
            cout << "]\n";
        }
        return 0;
    }