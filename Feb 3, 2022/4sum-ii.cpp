//Problem Name:-  454. 4Sum II
//Problem Link:- https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> num12Sum;

        for(int i:nums1){
            for(int j: nums2){
                num12Sum[i+j]++;
            }
        }
        int count = 0;

        for(int k: nums3){
            for(int l:nums4){
                int sum = k+l;
                if(num12Sum[0-sum]!=0) count+=num12Sum[0-sum];
            }
        }
        return count;
    }
};
