// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans;
        int i=a.length()-1;
        int j=b.length()-1;
        while(i>=0 || j>=0 || carry){
            int sum=0;
            if(i>=0){
                int d1=a[i]-'0';
                sum+=d1;
            }
            if(j>=0){
                int d2=b[j]-'0';
                sum+=d2;
            } 
            sum+=carry;   
            carry=sum/2;
            sum=sum%2;
            ans.append(to_string(sum));
            i--;
            j--;
        }
        if(carry) ans.append(to_string(carry));
        reverse(ans.begin(), ans.end());
        return ans;
    }
};