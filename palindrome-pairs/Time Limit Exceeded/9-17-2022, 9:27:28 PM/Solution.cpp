// https://leetcode.com/problems/palindrome-pairs

class Solution {
public:
    bool isPal(string s){
        string p=s;
        reverse(s.begin(),s.end());
        if(s==p) return true;
        else return false;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>v;
        for(int i=0;i<words.size();i++){
            vector<int>v1;
            for(int j=0;j<words.size();j++){
                if(j != i){
                if(isPal(words[i]+words[j])){
                    v1.push_back(i);
                    v1.push_back(j);
                    v.push_back(v1);
                    v1.clear();
                }
                }
            }
        }
        return v;
    }
};