/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> st;
        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            TreeNode* top= st.top();
            st.pop();
            ans.push_back(top->val);
            if(top->left) st.push(top->left); // push left element
            if(top->right) st.push(top->right); // push right element
        }
        reverse(ans.begin(),ans.end()); // reverse for post order
        return ans;
    }
};