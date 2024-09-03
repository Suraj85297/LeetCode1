class Solution {
public:
    int getLucky(string s, int k) {
        long long sum = 0;
        
        // Convert each character to its corresponding number and sum them
        for(int i = 0; i < s.size(); i++) {
            int alpha = s[i] - 'a' + 1; // 'a' corresponds to 1, 'b' to 2, ..., 'z' to 26
            if(alpha > 9) {
                sum += alpha % 10 + alpha / 10; // Sum the digits of the number
            } else {
                sum += alpha;
            }
        }
        
        // Apply the transformation k-1 times
        for(int i = 1; i < k; i++) {
            long long newSum = 0;
            while(sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }
        
        return sum;
    }
};
