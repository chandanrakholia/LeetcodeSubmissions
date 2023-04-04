// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string s=s2;
        string p=s1;
        map<int,int>mp;
        for(auto i: p) mp[i-'a']++;
        int ind1=0;      //Copy pasted same code from this: ->
        int ind2=0;     //https://leetcode.com/problems/find-all-anagrams-in-a-string/
        int n=s.length();
        int m=p.length();
        map<int,int> temp;
        vector<int> ans;
        while(ind2<n){
            if(ind2-ind1+1 < m){
                temp[s[ind2]-'a']++;
                cout<<"ind1: "<<ind1<<" "<<"ind2: "<<ind2<<endl;
                ind2++;
            }
            else if(ind2-ind1+1==m){
                cout<<"ind1: "<<ind1<<" "<<"ind2: "<<ind2<<endl;
                temp[s[ind2]-'a']++;
                if(temp==mp){
                    ans.push_back(ind1);
                    // cout<<ind1<<endl;
                }
                if(--temp[s[ind1]-'a']==0) temp.erase(s[ind1]-'a');
                ind1++;
                ind2++;
            }
            // cout<<ind2<<endl;
        }
        return ans.size();
    }
};