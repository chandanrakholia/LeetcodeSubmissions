// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        int t[n+1];
        t[0]=0;
        t[1]=1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                t[i]=t[i/2];
            }
            else{
                t[i]=t[(i-1)/2]+t[(i+1)/2];
            }
        }
        return t[n];
    }
};