class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN;
        double sum = 0;
        int i=0,j=0;
        for(j=0;j<k;j++){
            sum+=nums[j];
        }
        maxAvg = max(maxAvg,sum/k);
        while(j<nums.size()){
            sum+=nums[j++];
            sum-=nums[i++];

            maxAvg = max(maxAvg,sum/k);
        }
        return maxAvg;
    }
};
