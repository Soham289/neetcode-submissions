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
    int maxPathSum(TreeNode* root) {
        int msum=INT_MIN;
        height(root,msum);
        return msum;
    }
    int height(TreeNode* root,int &msum){
        if(!root) return 0;
        int lh = max(0,height(root->left,msum));
        int rh = max(0,height(root->right,msum));
        msum = max(msum,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
};
