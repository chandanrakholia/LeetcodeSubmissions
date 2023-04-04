// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        pair<int,int> dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0){
                    dp[i][j]={dungeon[i][j],dungeon[i][j]};
                }
                else if(i==0){
                    dp[i][j]={dp[i][j-1].first+dungeon[i][j],dp[i][j-1].second};
                }
                else if(j==0){
                    dp[i][j]={dp[i-1][j].first+dungeon[i][j],dp[i-1][j].second};
                }
                else{
                    if(dp[i-1][j].second>dp[i][j-1].second){
                        dp[i][j]={dp[i-1][j].first+dungeon[i][j],dp[i-1][j].second};
                    }
                    else{
                        dp[i][j]={dp[i][j-1].first+dungeon[i][j],dp[i][j-1].second};
                    }
                }
                if(dp[i][j].first<dp[i][j].second){
                    dp[i][j].second=dp[i][j].first;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<'{'<<dp[i][j].first<<','<<dp[i][j].second<<'}'<<' ';
            }
            cout<<endl;
        }
        return -dp[n-1][m-1].second+1;
    }
};