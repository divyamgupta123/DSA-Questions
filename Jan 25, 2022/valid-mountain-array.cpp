//Problem Name:- Leetcode 941. Valid Mountain Array
//Problem Link:- https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        if(size<3) return false;
        int i;
        for(i=0;i<size-1;i++){
            if(arr[i]==arr[i+1]) return false;
            if(arr[i+1]<arr[i]) break;
        }

        if(i==size-1 || i==0) return false;

        while(i<size-1){
            if(arr[i]==arr[i+1]) return false;
            if(arr[i+1]>arr[i]) return false;
            i++;
        }
        return true;
    }
};
