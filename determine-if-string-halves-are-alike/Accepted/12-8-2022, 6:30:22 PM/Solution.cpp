// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        int i=0;
        int j=s.length()-1;
        int jc=0;
        int ic=0;
        while(i<j){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o'||s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                ic++;
            }
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u' || s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
                jc++;
            }
            i++;j--;
        }
        cout<<ic<<endl;
        cout<<jc<<endl;
        return ic==jc;
    }
};