//Problem Name:- Leetcode 429. N-ary Tree Level Order Traversal
//Problem Link:- https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> result;
        if(!root) return result;
        vector<int> ds;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            for(int i=q.size();i>0;i--){
                Node* tmp = q.front();
                q.pop();
                ds.push_back(tmp->val);
                for(int i=0;i<tmp->children.size();i++){
                    q.push(tmp->children[i]);
                }
            }
            result.push_back(ds);
            ds.clear();
        }
        return result;
    }
};
