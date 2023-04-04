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
        int p=0;
        for(int i=0;i<nums.size()-1;i++){
            if(gcd(nums[i],nums[i+1])==1){
                p++;
                break;
            }
        }
        if(p>0){return true;}
        else{
            return false;
        }
    }
};