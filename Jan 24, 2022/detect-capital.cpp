//Problem Name:- LeetCode 520. Detect Capital
//Problem Link:- https://leetcode.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string s) {
        int len = s.length();
        if(len==1) return true;

        if(isupper(s[0]) && isupper(s[1])){
            for(int i=2;i<len;i++){
                if(!isupper(s[i])) return false;
            }
        }
        else{
            for(int i=1;i<len;i++){
                if(!islower(s[i])) return false;
            }
        }
        return true;
    }
};
