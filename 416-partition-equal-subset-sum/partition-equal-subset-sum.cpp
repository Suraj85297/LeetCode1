class Solution {
public:
    bool fn(vector<int> &nums, int target, int ind, vector <vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return nums[ind]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = fn(nums,target,ind-1, dp);
        bool take = false;
        if(target>=nums[ind]){
            take = fn(nums, target-nums[ind], ind-1, dp);
        }
        return dp[ind][target]=take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(int i=0; i<nums.size(); i++){
            totSum+=nums[i];
        }
        if(totSum % 2 != 0) return false;  // Early exit if total sum is odd

        int target=totSum/2;
        vector <vector <int>> dp (nums.size()+1,vector<int> (target+1,-1));
        return fn(nums, target, nums.size()-1, dp);
    }
};