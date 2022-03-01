// https://leetcode.com/problems/convert-bst-to-greater-tree/


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
    TreeNode* convertBST(TreeNode* root) {
        int tot = inorder(root);
        TreeNode* node = root;
        stack<TreeNode*> s;
        int prevSum = 0;
        //while(true) {
            while(node || !s.empty()) {
                if(node) {
                    s.push(node);
                    node = node->left;
                }
                else {
                    node = s.top();
                    s.pop();
                    int temp = node->val;
                    node->val = tot - prevSum;
                    prevSum += temp;
                    node = node->right;
                }
            }
        ///}
        return root;
    }
    int inorder(TreeNode* root) {
        if(root == NULL) return 0;
        if(!root->left && !root->right) return root->val;
        return root->val + inorder(root->left) + inorder(root->right);
    }
};
