// https://leetcode.com/problems/jump-game

class Solution {
public:
    void print(vector<bool>&istrue){
        for(auto i: istrue){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>istrue(n,0);
        int j=0;
        for(int i=0;i<n;i++){
            if(i==0){
                istrue[0]=true;
                j=i+nums[i];
            }
            else{
                if(j>=i){
                    istrue[i]=true;
                    j--;
                }
                else{
                    break;
                }
            }
            j=max(j, i+nums[i]);
            cout<<"j: "<<j<<endl;
        }
        print(istrue);
        return istrue[n-1];
    }
};