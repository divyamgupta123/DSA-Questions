//Problem Name:- Leetcode 1091. Shortest Path in Binary Matrix
//Problem Link:- https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
              if(grid[0][0] == 1) return -1;

        int size = grid.size();
        int dirX[8] = {1,1,0,-1,-1,-1,0,1};
        int dirY[8] = {0,1,1,1,0,-1,-1,-1};
        vector<vector<int>> dist(size,vector<int>(size,-1));
        queue<vector<int>> q;
        q.push({0,0});
        dist[0][0] = 1;

        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();

            for(int i=0;i<8;i++){
                int nextX = dirX[i] + curr[0];
                int nextY = dirY[i] + curr[1];
                if(nextX>=0 && nextX<size && nextY>=0 && nextY<size && grid[nextX][nextY]==0 && dist[nextX][nextY] == -1){
                    q.push({nextX,nextY});
                    dist[nextX][nextY] = dist[curr[0]][curr[1]]+1;
                }
            }
        }

        return dist[size-1][size-1];
    }
};
