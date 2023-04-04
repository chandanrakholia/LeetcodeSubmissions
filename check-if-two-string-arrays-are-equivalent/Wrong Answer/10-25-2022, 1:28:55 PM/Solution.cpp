// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0;
        int j=0;
        int x=0;
        int y=0;
        while(i<n && j<m){
            if(word1[i][x]!=word1[j][y]) return false;
            x++;y++;
            if(x>word1[i].size()){
                x=0;
                i++;
            }
            if(y>word2[j].size()){
                y=0;
                j++;
            }
        }
        return true;
    }
};