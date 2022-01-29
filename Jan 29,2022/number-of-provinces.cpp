//Problem Name:- 547. Number of Provinces
//Problem Link:- https://leetcode.com/problems/number-of-provinces/

class UnionFind{
private:
    vector<int> root;
    vector<int> rank;
    int count;
public:
    UnionFind(int size){
        for(int i=0;i<size;i++){
            root.push_back(i);
            rank.push_back(1);
        }
        count = size;
    }

    int find(int x){
        if(x == root[x]) return x;
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
            count--;
        }
    }

    int getCount(){
        return count;
    }
};

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        if(size==0) return 0;

        UnionFind uf = UnionFind(size);

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(isConnected[i][j]) uf.unionSet(i,j);
            }
        }
        return uf.getCount();
    }
};

