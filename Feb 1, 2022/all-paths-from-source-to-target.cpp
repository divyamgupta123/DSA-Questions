//Problem Name:- Leetcode 797. All Paths From Source to Target
//Problem Link:- https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:

    void dfs(vector<int> &ds,vector<vector<int>> &result,vector<vector<int>> graph,int src,int dst){
        ds.push_back(src);

        if(src == dst){
            result.push_back(ds);
            return;
        }

        for(int i=0;i<graph[src].size();i++){
            dfs(ds,result,graph,graph[src][i],dst);
            ds.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0;
        int dst = graph.size()-1;
        vector<vector<int>> result;
        vector<int> ds;
        dfs(ds,result,graph,src,dst);
        return result;
    }
};
