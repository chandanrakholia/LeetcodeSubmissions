// https://leetcode.com/problems/distinct-subsequences

class Solution {
private:
    int solver(string &s, string &t, int ind1, int ind2){
        if(ind2==0) return 1;
        if(ind1==0) return 0;
        if(s[ind1-1]==t[ind2-1]){
            return solver(s,t,ind1-1, ind2-1) + solver(s,t,ind1-1, ind2);
        }
        else{
            return solver(s,t,ind1-1,ind2);
        }
    }
public:
    int numDistinct(string s, string t) {
        return solver(s,t, s.length(), t.length());
    }
};