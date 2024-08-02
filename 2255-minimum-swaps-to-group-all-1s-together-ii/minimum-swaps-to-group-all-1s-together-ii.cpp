class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int currOnes = 0;
        int maxCount = 0;
        int i=0;
        int j=0;
        while(j<2*n){
            if(nums[j%n]==1){
                currOnes++;
            }
            if(j-i+1>totalOnes){
                if(nums[i%n]==1){
                    currOnes--;
                }
                i++;
            }
            maxCount=max(maxCount,currOnes);
            j++;
        }
        return totalOnes-maxCount;
    }
};