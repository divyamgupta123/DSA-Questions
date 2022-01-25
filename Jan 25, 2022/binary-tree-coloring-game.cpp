//Problem Name:- Leetcode 1145. Binary Tree Coloring Game
//Problem Link:- https://leetcode.com/problems/binary-tree-coloring-game/

class Solution {
    int left = 0,right=0;
public:
    int countNodes(TreeNode* root,int val){
        if(!root) return 0;
        int leftnodes = countNodes(root->left,val);
        int rightnodes = countNodes(root->right,val);
        if(root->val == val){
            left = leftnodes;
            right = rightnodes;
        }
        return leftnodes+rightnodes+1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        countNodes(root,x);

        // if player2 chooses player1's parent node and payer1 node's count is smaller than n/2, playr2 will win
        if(left+right+1<(n+1)/2) return true;
        // if player2 chooses player1's left or right node and its count is bigger than n/2, playr2 will win
        if(left>n/2 || right>n/2) return true; // player 2 takes the root;

        return false;

    }
};
