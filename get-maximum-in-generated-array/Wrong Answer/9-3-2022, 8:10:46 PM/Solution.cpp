// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        int t[n+1];
        t[0]=0;
        t[1]=1;
        int max=INT_MIN;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                t[i]=t[i/2];
            }
            else{
                t[i]=t[(i-1)/2]+t[(i+1)/2];
            }
                if(t[i]>max){max=t[i];}
            
        }
        return max;
    }
};