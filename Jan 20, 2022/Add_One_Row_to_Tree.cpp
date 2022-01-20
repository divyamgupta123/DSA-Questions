//623. Add One Row to Tree
//Question link:- https://leetcode.com/problems/add-one-row-to-tree/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int currDepth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(currDepth<depth-1){
            queue<TreeNode*> tmpQ;
            while(!q.empty()){

                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left) tmpQ.push(tmp->left);
                if(tmp->right) tmpQ.push(tmp->right);
            }
            q = tmpQ;
            currDepth++;
        }


        while(!q.empty()){

            TreeNode* fr = q.front();
            q.pop();
            TreeNode* tmp = fr->left;

            fr->left = new TreeNode(val);
            fr->left->left = tmp;

            tmp = fr->right;
            fr->right = new TreeNode(val);
            fr->right->right = tmp;
        }

        return root;
    }
};

