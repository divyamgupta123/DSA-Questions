//Problem Name:- LeetCode 1208. Get Equal Substrings Within Budget
//Problem Link:- https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {


        int i=0,j=0;
        int sum = 0;
        int maxLen = INT_MIN;
        for(;j<s.length();j++){
            sum+=abs(s[j]-t[j]);
            while(sum>maxCost){
                sum-=(abs(s[i]-t[i]));
                i++;
            }
            maxLen = max(maxLen,j-i+1);
        }
        return maxLen;
    }
};
