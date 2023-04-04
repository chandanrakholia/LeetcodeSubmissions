// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        int i=tx;
        int j=ty;
        while(i>=sx and j>=sy){
            // while(i%2==0) i/=2;
            // while(j%2==0) j/=2;
            cout<<"i: "<<i<<" "<<"j: "<<j<<endl;
            if(i>j){
                i-=j;
            }
            else{
                if(i==sx and j==sy) break;
                j-=i;
            }
        }
        return i==sx and j==sy;
    }
};