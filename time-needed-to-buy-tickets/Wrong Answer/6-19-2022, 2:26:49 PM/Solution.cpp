// https://leetcode.com/problems/time-needed-to-buy-tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
            }
        int count=0;
        int f=0;
    while(q.size()>0){
        if(q.front().second==k and q.front().first==0){
            // f==count;
            break;
        }
        else if(q.front().first==0){
            q.pop();
        }
        else if(q.front().first>0){
            q.push({q.front().first-1,q.front().second});
            q.pop();
            count++;
        }
    }
        return count-1;
    }
};