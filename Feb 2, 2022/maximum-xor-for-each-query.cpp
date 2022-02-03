//Problem Name:-  1829. Maximum XOR for Each Query
//Problem Link:- https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        //Note that the maximum possible XOR result is always 2^(maximumBit) - 1
        //So the answer for a prefix is the XOR of that prefix XORed with 2^(maximumBit)-1

        int size = nums.size();
        vector<int> result;
        int maxXor = pow(2,maximumBit)-1;
        for(int i=1;i<size;i++){
            nums[i]^=nums[i-1];
        }
        for(int i=size-1;i>=0;i--){
            result.push_back(nums[i]^maxXor);
        }
        return result;
    }
};
