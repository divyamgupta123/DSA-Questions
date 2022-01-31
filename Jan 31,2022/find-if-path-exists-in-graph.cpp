//Problem Name:- Leetcode 1971. Find if Path Exists in Graph
//Problem Link:- https://leetcode.com/problems/find-if-path-exists-in-graph/

class UnionFind{
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int size){
        for(int i=0;i<size;i++){
            root.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int x){
        if(x==root[x]) return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x,int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]) root[rootY] = rootX;
            else if(rank[rootX]<rank[rootY]) root[rootX] = rootY;
            else{
                root[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        //Solution 1
        /*vector<vector<int>> adjList(n);

        for(vector<int> edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        stack<int> s;
        s.push(source);
        vector<int> vis(n,0);

        while(!s.empty()){
            int node = s.top();
            s.pop();

            if(node == destination) return true;

            if(vis[node] == 1) continue;

            vis[node] = 1;

            for(int neighbour: adjList[node]){
                s.push(neighbour);
            }
        }
        return false;*/

        //Solution 2
        UnionFind uf(n);

        for(vector<int> edge:edges){
            uf.unionSet(edge[0],edge[1]);
        }
        return uf.find(source) == uf.find(destination);
    }
};


