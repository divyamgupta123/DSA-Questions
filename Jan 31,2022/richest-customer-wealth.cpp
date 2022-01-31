//Problem Name:- Leetcode 1672. Richest Customer Wealth
//Problem Link:- https://leetcode.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;

        for(auto i:accounts){
            int sum = 0;
            for(int j:i){
                sum+=j;
            }
            result = max(result,sum);
        }
        return result;
    }
};
