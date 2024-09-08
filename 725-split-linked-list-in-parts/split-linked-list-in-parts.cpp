/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Compute the length of the list
        int L = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            L++;
            curr = curr->next;
        }
        
        // Step 2: Compute bucket sizes
        int remainderNodes = L % k;     // Extra nodes to distribute
        int bucketSize = L / k;         // Base size of each part
        
        vector<ListNode*> result(k, NULL);
        curr = head;  // Reset curr to head
        
        // Step 3: Split the list into parts
        for (int i = 0; i < k && curr != NULL; i++) {
            result[i] = curr;
            int partSize = bucketSize + (remainderNodes > 0 ? 1 : 0);
            
            // Step 4: Traverse to the end of the current part
            ListNode* prev = NULL;
            for (int j = 0; j < partSize; j++) {
                prev = curr;
                curr = curr->next;
            }
            
            // Step 5: Break the link to split the list
            if (prev != NULL) {
                prev->next = NULL;
            }
            remainderNodes--;
        }
        
        return result;
    }
};
