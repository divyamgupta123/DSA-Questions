//Problem Name:- LeetCode 958. Check Completeness of a Binary Tree
//Problem Link:- https://leetcode.com/problems/check-completeness-of-a-binary-tree/

class Solution {
public:

    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        int i=0;
        bfs.push_back(root);

        while(i<bfs.size() && bfs[i]){
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }

        while (i < bfs.size() && !bfs[i])
            i++;
        return i == bfs.size();
    }
};

