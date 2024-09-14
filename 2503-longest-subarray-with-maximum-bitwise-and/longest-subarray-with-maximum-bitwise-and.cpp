class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());  // Find the maximum number
        int longest = 0, current_length = 0;

        for (int num : nums) {
            if (num == max_num) {
                // If the current number equals the maximum number, increment the length of the current subarray
                current_length++;
                longest = max(longest, current_length);
            } else {
                // Reset the current subarray length if the number is not equal to the maximum number
                current_length = 0;
            }
        }

        return longest;
    }
};
