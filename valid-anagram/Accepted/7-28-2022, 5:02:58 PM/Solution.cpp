// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        bool flag=true;
        int x=s.length();
        int y=t.length();
        if(x!=y){
            flag=false;
        }
        else{        
        for(int i=0;i<x;i++){
            if(s[i]!=t[i]){
                flag=false;
                break;
            }
        }
        }
        if(flag==false){
            return false;
        }
        else{
            return true;
        }
    }
};