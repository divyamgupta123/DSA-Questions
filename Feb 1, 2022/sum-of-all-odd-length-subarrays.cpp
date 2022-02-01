//Problem Name:- Leetcode 1588. Sum of All Odd Length Subarrays
//Problem Link:- https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size();
        for(int i=1;i<size;i++)
            arr[i]+=arr[i-1];

        int result=0;
        int subSize = 1;

        while(subSize<=size){
            for(int i=0;i<=size-subSize;i++){
                if(i==0) result+=arr[i+subSize-1];
                else result+=(arr[i+subSize-1]-arr[i-1]);
            }
            subSize+=2;
        }
        return result;
    }
};
