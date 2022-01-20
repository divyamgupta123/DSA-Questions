//Problem Name:- LeetCode 290. Word Pattern
//Problem Link:- https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> cs;
        unordered_map<string,char> sc;
        vector<string> v;
        int tmp = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
              v.push_back(s.substr(tmp,i-tmp));
                tmp = i+1;
            }
        }
        v.push_back(s.substr(tmp,s.length()-tmp));
        if(pattern.length()!=v.size()) return false;
        for(int i=0;i<v.size();i++){
            if(cs.find(pattern[i])==cs.end() && sc.find(v[i])==sc.end()){
                cs[pattern[i]] = v[i];
                sc[v[i]] = pattern[i];
            }
            else if(cs.find(pattern[i])==cs.end() || sc.find(v[i])==sc.end()) return false;
            else if(cs[pattern[i]]!=v[i]) return false;

        }
        return true;
    }
};
