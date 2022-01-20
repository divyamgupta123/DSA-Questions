//Problem Name:- Leetcode 978. Longest Turbulent Subarray
//Problem Link:- https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();

        if(size==1 || (size == 2 && arr[0]==arr[1])) return 1;
        if(size == 2 && arr[0]!=arr[1]) return 2;

        int count = (arr[0] != arr[1]) ? 2 : 1;
        int maxCount = count;

        bool isLess = arr[0]<arr[1];

        int j=0;

        for(j=1;j<size-1;j++){

            if(isLess == false && arr[j]<arr[j+1]){
                count++;
                maxCount = max(maxCount,count);
            }
            else if(isLess == true && arr[j]>arr[j+1]){
                count++;
                maxCount = max(maxCount,count);
            }
            else{
                count = (arr[j] != arr[j+1]) ? 2 : 1;
            }
            isLess = arr[j]<arr[j+1];
        }
        return maxCount;
    }

};
