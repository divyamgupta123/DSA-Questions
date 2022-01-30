//Problem Name:- LeetCode 2154. Keep Multiplying Found Values by Two
//Problem Link:- https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        while(m[original]!=0){
            m.erase(original);
            original*=2;
        }
        return original;
    }
};
