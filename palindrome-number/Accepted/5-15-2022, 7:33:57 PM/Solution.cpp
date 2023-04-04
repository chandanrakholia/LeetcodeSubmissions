// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        long long int n=x;
        long long int rev=0;
        while(n>0){
            rev=rev*10+n%10;
            n=n/10;
        }
        cout<<rev<<endl;
        if(x==rev){
            return true;
        }
        else{
            return false;
        }
    }
};