// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    void rev(int &n){
        int m=0;
        while(n>0){
            m=m*10;
            m+=n%10;
            n/=10;
        }
        n=m;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
       reverse(num.begin(), num.end());
       vector<int>ans;
       int carry=k%10;
       k/=10;
       int i=0;
       int n=num.size();
       while(carry || i<n){
           int sum=0;
           if(i<n){
                sum=num[i]+carry;
           }
           else{
               sum=carry;
           }
           carry=sum/10 +k%10;
           int digit=sum%10;
           k/=10;
           ans.push_back(digit);
           i++;
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
};