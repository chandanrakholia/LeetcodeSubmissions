// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> myorginal(vector<int>& nums, int n){
        vector<int>ans;
        int i=0;
        int j=n;
        while(j < 2*n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;j++;
        }
        return ans;
    }
    vector<int> anotherwayofimplementation(vector<int>& nums, int n){
        vector<int>ans(2*n);
        for(int i=0;i<n;i++){
            ans[2*i]=nums[i];
            ans[2*i+1]=nums[n+i];
        }
        return ans;
    }
    vector<int> Optimized_with_BITMANIPULATION(vector<int>& nums, int n){
        // Store each y(i) with respective x(i).
        for (int i = n; i < 2 * n; ++i) {
            int secondNum = nums[i] << 10;
            nums[i - n] |= secondNum;
        }

        // '0000000000 1111111111' in decimal.
        int allOnes = pow(2, 10) - 1;

        // We will start putting all numbers from the end, 
        // as they are empty places.
        for (int i = n - 1; i >= 0; --i) {
            // Fetch both the numbers from the current index.
            int secondNum = nums[i] >> 10;
            int firstNum = nums[i] & allOnes;
            nums[2 * i + 1] = secondNum;
            nums[2 * i] = firstNum;
        }
        return nums;
    }
    vector<int> shuffle(vector<int>& nums, int n) {
        // return myoriginal(nums, n);
        // return anotherwayofimplementation(nums, n);
        return Optimized_with_BITMANIPULATION(nums, n);
    }
};