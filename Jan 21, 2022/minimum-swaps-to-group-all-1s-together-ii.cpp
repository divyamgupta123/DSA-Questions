class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum = 0;
        int totalOne = 0;
        int countZero = 0;
        for(int i:nums)
            if(i==1) totalOne++;

        int oneCurrWindow = 0;
        int winSize = totalOne;
        int maxOnes = INT_MIN;
        int i=0;
        for(i=0;i<winSize;i++){
            if(nums[i]==1) oneCurrWindow++;
        }
        maxOnes = oneCurrWindow;
        int n = nums.size();
        for(;i<n+winSize;i++){
            oneCurrWindow = oneCurrWindow + nums[i%n] - nums[(i-winSize)%n];
            maxOnes = max(maxOnes,oneCurrWindow);
        }
        return totalOne-maxOnes;
    }
};
