//Problem Name:- LeetCode 1202. Smallest String With Swaps
//Problem Link:- https://leetcode.com/problems/smallest-string-with-swaps/

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
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    void unionSet(int x,int y){
        int xRoot = find(x);
        int yRoot = find(y);

        if(xRoot!=yRoot){
            if(rank[xRoot]>rank[yRoot]) root[yRoot] = xRoot;
            else if(rank[xRoot]<rank[yRoot]) root[xRoot] = yRoot;
            else{
                root[xRoot] = yRoot;
                rank[yRoot]++;
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int pairSize = pairs.size();
        int sSize = s.length();
        UnionFind uf(sSize);

        for(int i=0;i<pairSize;i++){
            uf.unionSet(pairs[i][0],pairs[i][1]);
        }

        unordered_map<int,vector<int>> m;
        for(int i=0;i<sSize;i++){
            m[uf.find(i)].push_back(i);
        }
        for(auto i:m){
            string tmp = "";
            for(int j:i.second)
                tmp+=s[j];

            sort(tmp.begin(),tmp.end());

            int k=0;
            for(int j:i.second)
                s[j] = tmp[k++];
        }
        return s;
    }
};
