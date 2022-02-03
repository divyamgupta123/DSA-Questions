//Problem Name:-  994. Rotting Oranges
//Problem Link:- https://leetcode.com/problems/rotting-oranges/

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;
        int fresh = 0;

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        queue<pair<int,int>> q;


        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }


        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto tmp = q.front();
                q.pop();

                int x = tmp.first;
                int y = tmp.second;

                for(auto dir:dirs){
                    int newRow = x+dir[0];
                    int newCol = y+dir[1];

                    if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && grid[newRow][newCol]==1){
                        grid[newRow][newCol]=2;
                        q.push({newRow,newCol});
                        fresh--;
                    }

                }

            }
            if(!q.empty()) ans++;
        }
        return fresh>0?-1:ans;

    }
};
