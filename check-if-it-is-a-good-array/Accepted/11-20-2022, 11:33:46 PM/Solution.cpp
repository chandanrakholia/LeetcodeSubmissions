// https://leetcode.com/problems/check-if-it-is-a-good-array

class Solution {
public:
bool isprime(int n){
    bool f=true;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            f=false;
            break;
        }
    }
    return f;
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}
    bool isGoodArray(vector<int>& nums) {
        int p=nums[0];
        for(int i=1;i<nums.size();i++){
            p=gcd(p,nums[i]);
        }
        if(p==1){return true;}
        else{
            return false;
        }
    }
};