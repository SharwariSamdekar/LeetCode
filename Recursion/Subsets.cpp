class Solution {
public:
    //f takes a suffic subarray and returns the set of possible subsets
    void f(vector<int> &nums, int startIdx, vector<int> currSet, vector<vector<int>> &res){
        int n = nums.size();
        // Base Case
        if(startIdx == n){
            res.push_back(currSet);
            return;
        }
        
        // Recursive Step
        // Ith element is the smallest element of subset
        
        // No element is the smallest
        f(nums, n, currSet,res);
        
        // ith element is the smallest
        for(int i = startIdx; i < n; i++){
            currSet.push_back(nums[i]);
            f(nums, i+1, currSet, res);
            currSet.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     //Framework for developing recursive solutions
     //1. optimisation problems or 2. combinatorical problems
     //Come up with a decision
     //Define subproblem
     //Define the recurrence, vision statement & function prototype
     //Define base cases
     //Implement the solution
        vector<vector<int>> res;
        vector<int> currSet;
        sort(nums.begin(),nums.end());
        f(nums,0,currSet,res);
        return res;
    }
};
