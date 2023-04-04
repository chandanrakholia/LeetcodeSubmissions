// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        for(int i = 0;i < s.length();i++){
        bool f = true;
        for(int j = i+1;j < s.length();j++){
            if(s[i] == s[j]){
                f = false;
                break;
            }
        }
        if(f == true){
            return i;
        }
    }
    return -1; 
    }
};