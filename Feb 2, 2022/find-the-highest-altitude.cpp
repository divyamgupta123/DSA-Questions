//Problem Name:-  Leetcode 1732. Find the Highest Altitude
//Problem Link:- https://leetcode.com/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int size = gain.size();
        int maxAlt = gain[0];
        for(int i=1;i<size;i++){
            gain[i]+=gain[i-1];
            maxAlt = max(maxAlt,gain[i]);
        }
        return max(0,maxAlt);
    }
};
