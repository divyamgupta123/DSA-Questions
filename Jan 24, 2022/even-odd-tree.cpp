//Problem Name:- LeetCode 1609. Even Odd Tree
//Problem Link:- https://leetcode.com/problems/even-odd-tree/

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()){
            vector<int> v;
            for(int i=q.size();i>0;i--){
                TreeNode* tmp = q.front();
                q.pop();

                if(level%2==0 && tmp->val%2 == 0) return false;
                if(level%2!=0 && tmp->val%2 != 0) return false;
                v.push_back(tmp->val);

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }

            if(level&1){
                for(int i=0;i<v.size()-1;i++){
                    if(v[i]<=v[i+1]) return false;
                }
            }else{
                for(int i=0;i<v.size()-1;i++){
                    if(v[i]>=v[i+1]) return false;
                }
            }
            level++;

        }
        return true;
    }
};
