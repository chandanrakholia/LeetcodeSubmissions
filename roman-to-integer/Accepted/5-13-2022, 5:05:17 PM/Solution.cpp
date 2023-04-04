// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        map<char,int>m;
        m.insert({'I',1});
        m.insert({'V',5});
        m.insert({'X',10});
        m.insert({'L',50});
        m.insert({'C',100});
        m.insert({'D',500});
        m.insert({'M',1000});
        
        int c=0,l=s.size(),i=0;
        while(i<l){
            if(s[i]=='I' && s[i+1]=='V'){
                c=c+m['V']-m['I'];
                i=i+2;
            }
            else if(s[i]=='I' && s[i+1]=='X'){
                c=c+m['X']-m['I'];
                i=i+2;
            }
            else if(s[i]=='X' && s[i+1]=='L'){
                c=c+m['L']-m['X'];
                i=i+2;
            }
            else if(s[i]=='X' && s[i+1]=='C'){
                c=c+m['C']-m['X'];
                i=i+2;
            }
            else if(s[i]=='C' && s[i+1]=='D'){
                c=c+m['D']-m['C'];
                i=i+2;
            }
            else if(s[i]=='C' && s[i+1]=='M'){
                c=c+m['M']-m['C'];
                i=i+2;
            }
            else{
                c=c+m[s[i]];
                i++;
            }
        }
        return c;
    }
    
};