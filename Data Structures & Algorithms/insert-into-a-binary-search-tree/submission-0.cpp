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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }

        TreeNode* head = root;
        TreeNode* parent = nullptr;
        while(root != nullptr){
            parent = root;
            if(val < root->val){
                root = root->left;
            }else{
                root = root->right;
            }
        }

        TreeNode* node = new TreeNode(val);

        if(val < parent->val){
            parent->left = node;
        }else{
            parent->right = node;
        }

        return head;
    }
};










