// https://leetcode.com/problems/stone-game

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice=0;
        int bob=0;
        int i=0;
        int j=piles.size()-1;
        int chance=0;
        while(i<j){
            if(piles[i]>piles[j]){
                if(chance==0){
                    alice+=piles[i];
                    chance=1;
                }
                else{
                    bob+=piles[i];
                    chance=0;
                }
                i++;
            }
            else{
                if(chance==0){
                    alice+=piles[j];
                    chance=1;
                }
                else{
                    bob+=piles[j];
                    chance=0;
                }
                j--;
            }
        }
        return alice>bob;
    }
};