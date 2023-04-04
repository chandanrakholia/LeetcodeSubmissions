// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // vector<int> ans;
        // for(int i=0;i<nums.size()-k+1;i++){
        //     int mx=INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //         if(nums[j]>mx){              //BRUTEFORCE METHOD
        //             mx=nums[j];              // O(n^2)
        //         }
        //     }
        //     ans.push_back(mx);
        // }
        // return ans;
        vector<int>ans;
        int i=0;
        int j=0;
        queue<int>q;
        while(j<nums.size()){
            if(j-i+1<k){
                if(q.size()>0){
                    if(q.front()<=nums[j]){
                        while(!q.empty()){
                            q.pop();
                        }
                    }
                    q.push(nums[j]);
                }
                else{
                    q.push(nums[j]);
                }
                j++;
            }
            else if(j-i+1==k){
                if(q.front()<=nums[j]){
                    while(!q.empty()){
                        q.pop();
                    }
                }
                q.push(nums[j]);
                ans.push_back(q.front());
                if(q.front()==nums[i]){
                    q.pop();
                }
                j++;i++;
            }
        }
        return ans;
    }
};