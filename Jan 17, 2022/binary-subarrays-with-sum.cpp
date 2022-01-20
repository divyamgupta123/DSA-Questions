//Problem Name:- Leetcode 930. Binary Subarrays With Sum
//Problem Link:- https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int size = nums.size();
        for(int i=1;i<size;i++){
            nums[i] = nums[i-1] + nums[i];
        }

        int ans = 0;
        unordered_map<int,int> m;
        for(int i=0;i<size;i++){
            if(nums[i]==goal) ans++;
            ans+=m[nums[i]-goal];
            m[nums[i]]++;
        }
        return ans;
    }
};
