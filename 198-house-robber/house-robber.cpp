class Solution {
public:
    /*int solve(int ind, vector <int> &nums, vector<int> &dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int pick=nums[ind]+solve(ind-2,nums, dp);
        int nonpick=0+solve(ind-1,nums, dp);

        return dp[ind]=max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector <int> dp(n,-1);
        return solve(n-1,nums,dp);
    }*/
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1; i<n; i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int nontake=0+prev;
            int curri=max(take,nontake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};