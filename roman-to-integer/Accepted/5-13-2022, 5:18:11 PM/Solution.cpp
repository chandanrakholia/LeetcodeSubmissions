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
        int sum=0;
        int i=0;
        while (i<s.size())
        {
            if (m[s[i]]<m[s[i+1]])
            {
                sum=sum+m[s[i+1]]-m[s[i]];
                i=i+2;
            }
            else if(m[s[i]]>=m[s[i+1]]){
                sum=sum+m[s[i]];
                i=i+1;
            }
            
        }
        return sum;
    }
    
};