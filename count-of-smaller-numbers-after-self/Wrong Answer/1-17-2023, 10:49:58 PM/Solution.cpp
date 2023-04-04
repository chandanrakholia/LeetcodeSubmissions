// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    void print(vector<pair<int,int>> &L){
        for(auto i: L){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
    void print1(vector<int> &ans){
        for(auto i: ans){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    void merge(vector<pair<int,int> > &v, int l, int m ,int r, vector<int> &ans){
        vector<pair<int,int> > temp(r-l+1);
        int i=l;
        int j=m+1;
        int k=0;
        while(i<=m and j<=r){
            if(v[i].first<=v[j].first){
                temp[k++]=v[j++];
            }
            else{
                ans[v[i].second]+=(r-j+1);
                temp[k++]=v[i++];
            }
        }
        print1(ans);
        while(i<=m){
            temp[k++]=v[i++];
        }
        while(j<=r){
            temp[k++]=v[j++];
        }
        for(int p=l; p<=r;p++){
            v[l]=temp[p-l];
        }
    }
    void mergesort(vector<pair<int,int> > &v, int l, int r, vector<int> &ans){
        if(l>=r) return;
        int m=(l+r)/2;
        mergesort(v,l, m, ans);
        mergesort(v, m+1, r, ans);
        merge(v,l, m ,r, ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int> > v(n);
        for(int i=0;i<n;i++){
            v[i]={nums[i], i};
        }
        vector<int> ans(n);
        mergesort(v,0, n-1, ans);
        // print(v);
        return ans;
    }
};