class Solution {
public:
    int getLucky(string s, int k) {
        long long sum = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int alpha = s[i] - 'a'+1;
            if(alpha > 9) {
                sum += alpha % 10 + alpha / 10;
            } else {
                sum += alpha;
            }
        }
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
