//Problem Name:- LeetCode 543. Diameter of Binary Tree
//Problem Link:- https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:

    int helper(TreeNode* root,int &maxDepth){
        if(!root) return 0;

        int leftDepth = helper(root->left,maxDepth);
        int rightDepth = helper(root->right,maxDepth);
        maxDepth = max(maxDepth, leftDepth+rightDepth);

        return max(rightDepth,leftDepth)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDepth = 0;
        helper(root,maxDepth);
        return maxDepth;
    }
};
