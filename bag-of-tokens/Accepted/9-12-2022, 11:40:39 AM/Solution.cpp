// https://leetcode.com/problems/bag-of-tokens

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0;
        int n=tokens.size();
        int j=n-1;
        vector<int>v;
        if( n==0 || tokens[0]>power) return 0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                power-=tokens[i];
                i++;
                v.push_back(score);
            }
            else{
                score--;
                power+=tokens[j];
                j--;
                v.push_back(score);
            }
            
        }
        return *max_element(v.begin(),v.end());
    }
};