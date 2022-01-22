//Problem Name:- 993. Cousins in Binary Tree
//Problem Link:- https://leetcode.com/problems/cousins-in-binary-tree/

class Solution {
public:
    int xDepth = -1,yDepth = -2;
    TreeNode* xParent = NULL,*yParent = NULL;
    void dfs(TreeNode* root,TreeNode* parent, int x,int y,int depth){
        if(!root) return;
        if(root->val == x){
            xDepth = depth;
            xParent = parent;
        }
        else if(root->val == y){
            yDepth = depth;
            yParent = parent;
        }
        else{
            dfs(root->left,root,x,y,depth+1);
            dfs(root->right,root,x,y,depth+1);
        }
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,NULL,x,y,0);
        return xDepth==yDepth && xParent!=yParent;
    }
};
