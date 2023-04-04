// https://leetcode.com/problems/check-if-point-is-reachable

class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int i=targetX;
        int j=targetY;
        while(i>0 and j>0){
            while(i%2==0) i/=2;
            while(j%2==0) j/=2;
            cout<<"i: "<<i<<" "<<"j: "<<j<<endl;
            if(i>j){
                i-=j;
            }
            else{
                if(i==1 and j==1) break;
                j-=i;
            }
        }
        return i==1 and j==1;
    }
};