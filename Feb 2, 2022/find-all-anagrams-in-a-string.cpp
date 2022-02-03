//Problem Name:-  Leetcode 438. Find All Anagrams in a String
/Problem Link:- https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        if(pLen>sLen) return {};

        vector<int> result;
        vector<int> sHash(26,0);
        vector<int> pHash(26,0);
        int left = 0;
        int right = 0;

        while(right<pLen){
            pHash[p[right]-'a']++;
            sHash[s[right]-'a']++;
            right++;
        }

        if(sHash==pHash) result.push_back(left);

        while(right<sLen){
            sHash[s[right]-'a']++;
            sHash[s[left]-'a']--;
            left++;
            right++;

            if(sHash==pHash) result.push_back(left);
        }
        return result;
    }
};
