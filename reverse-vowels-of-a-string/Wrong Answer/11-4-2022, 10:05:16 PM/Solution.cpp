// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        vector<char>v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' ||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                v.push_back(s[i]);
                s[i]='>';
            }
        }
        // reverse(v.begin(),v.end());
        int j=v.size()-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='>'){
                s[i]=v[j];
                j--;

            }
        }
        return s;
    }
};