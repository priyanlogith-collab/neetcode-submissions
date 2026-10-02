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
    TreeNode* findNode(TreeNode* root){
        if(root->right){
            root = root->right;
            while(root->left != nullptr){
                root = root->left;
            }
        }
        
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }
        
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }

            if(root->left == nullptr){
                TreeNode* temp = root->right; 
                delete root;
                return temp;
            }

            if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* node = findNode(root);
            root->val = node->val;
            root->right = deleteNode(root->right, node->val);
        }
        return root;
    }
};

















