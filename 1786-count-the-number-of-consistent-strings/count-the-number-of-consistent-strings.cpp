class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        // Create a bitmask for allowed characters
        for (char c : allowed) {
            mask |= (1 << (c - 'a'));
        }

        int count = 0;
        for (string word : words) {
            bool allCharPresent = true;
            for (char ch : word) {
                // Check if the character is not allowed
                if ((mask & (1 << (ch - 'a'))) == 0) {
                    allCharPresent = false;
                    break;
                }
            }
            if (allCharPresent) {
                count++;
            }
        }

        return count;
    }
};
