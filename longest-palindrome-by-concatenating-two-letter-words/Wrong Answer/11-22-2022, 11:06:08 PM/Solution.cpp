// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int arr[26][26]={0};
        for(int i=0;i<words.size();i++){
            arr[int(words[i][0]-'a')][int(words[i][1]-'a')]++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<i;j++){
                ans+=2*min(arr[i][j],arr[j][i]);
                cout<<arr[i][j]<<' ';
            }
            cout<<endl;
        }
        int maxi=0;
        for(int i=0;i<26;i++){
            if(maxi<arr[i][i]){maxi=arr[i][i];}
        }
        ans+=maxi;
        return 2*ans;
    }
};