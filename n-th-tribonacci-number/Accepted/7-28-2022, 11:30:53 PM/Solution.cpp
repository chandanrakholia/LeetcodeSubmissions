// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int arr[40]={0};
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(arr[n]!=0) return arr[n];
        else{
            return arr[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        }
    }
};