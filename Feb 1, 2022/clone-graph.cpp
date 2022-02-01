//Problem Name:- Leetcode 133. Clone Graph
//Problem Link:- https://leetcode.com/problems/clone-graph/

class Solution {
private:
    unordered_map<Node*,Node*> copies;

public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        if(copies.find(node) == copies.end()){
            copies[node] = new Node(node->val,{});
            for(auto neighbor: node->neighbors){
                (copies[node]->neighbors).push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
};
