
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        
        // Handle edge cases
        if (n == "1") return "0";  // Special case for "1"
        
        // Generate candidates
        long num = stol(n);
        vector<long> candidates;
        
        // Edge case candidates
        candidates.push_back(pow(10, len - 1) - 1); // Lower boundary (e.g., "999" for "1000")
        candidates.push_back(pow(10, len) + 1);     // Upper boundary (e.g., "10001" for "9999")
        
        // Middle number mirroring
        string prefix = n.substr(0, (len + 1) / 2);
        long prefix_num = stol(prefix);
        
        // Candidates by mirroring the first half
        candidates.push_back(createPalindrome(prefix_num, len % 2 == 0));
        candidates.push_back(createPalindrome(prefix_num - 1, len % 2 == 0));
        candidates.push_back(createPalindrome(prefix_num + 1, len % 2 == 0));
        
        // Determine the closest palindrome
        long closest = -1;
        for (long candidate : candidates) {
            if (candidate == num) continue;  // Skip the original number
            if (closest == -1 ||
                abs(candidate - num) < abs(closest - num) ||
                (abs(candidate - num) == abs(closest - num) && candidate < closest)) {
                closest = candidate;
            }
        }
        
        return to_string(closest);
    }
    
private:
    long createPalindrome(long half, bool evenLength) {
        string half_str = to_string(half);
        string palindrome = half_str;
        if (!evenLength) half_str.pop_back();  // Remove the middle digit for odd length
        reverse(half_str.begin(), half_str.end());
        palindrome += half_str;
        return stol(palindrome);
    }
};
