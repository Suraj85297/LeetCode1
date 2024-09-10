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
    int GCD(int a, int b){
        int max=INT_MIN;
        for(int i=1; i<=min(a,b); i++){
            if(a%i==0 && b%i==0){
                max=i;
            }
        }
        return max;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head; // If the list is empty or has only one node, return as is
        
        ListNode* curr = head;
        
        // Traverse the linked list
        while (curr != NULL && curr->next != NULL) {
            int gcdValue = GCD(curr->val, curr->next->val);  // Find GCD of current node's value and next node's value
            
            // Create a new node with the GCD value
            ListNode* newNode = new ListNode(gcdValue);
            
            // Insert the new node between `curr` and `curr->next`
            newNode->next = curr->next;
            curr->next = newNode;
            
            // Move to the next original node (skip over the inserted GCD node)
            curr = newNode->next;
        }
        
        return head;
    }
};