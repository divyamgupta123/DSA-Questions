//Problem Name:- LeetCode 904. Fruit Into Baskets
//Problem Link:- https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = INT_MIN;
        unordered_map<int,int> m;
        int i=0,j=0;
        while(j<fruits.size()){
            m[fruits[j++]]++;
            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
                i++;
            }
            result = max(result,j-i);
        }
        return result;
    }
};
