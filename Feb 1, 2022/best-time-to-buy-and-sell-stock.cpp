//Problem Name:- Leetcode 121. Best Time to Buy and Sell Stock
//Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int size = nums.size()-1;
        int maxPrice = nums[size];
        int result = 0;
        for(int i=size-1;i>=0;i--){
            if(nums[i]<maxPrice) result = max(result,maxPrice-nums[i]);
            else maxPrice = nums[i];
        }
        return result;
    }
};
