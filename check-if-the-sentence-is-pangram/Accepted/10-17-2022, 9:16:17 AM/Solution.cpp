// https://leetcode.com/problems/check-if-the-sentence-is-pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>set;
        for(int i=0;i<sentence.length();i++){
            set.insert(sentence[i]);
        }
        if(set.size()==26) return true;
        else return false;
    }
};