// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    void print(vector<pair<int,int>> &L){
        for(auto i: L){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
    void merge(vector<pair<int,int> > &v, int l, int m ,int r, vector<int> &ans){
        int n1=m-l+1;
        int n2=r-m;
        vector<pair<int,int>> L(n1);
        vector<pair<int,int>> R(n2);
        for(int i=0;i<n1;i++){
            L[i]=v[l+i];
        }
        for(int j=0;j<n2;j++){
            R[j]=v[m+1+j];
        }
        cout<<"L:"<<endl;
        print(L);
        cout<<"R: "<<endl;
        print(R);
        int i=0;
        int j=0;
        int k=l;
        while(i<n1 and j<n2){
            if(L[i]<=R[j]){
                v[k]=L[i];
                k++;
                i++;
            }
            else{
                v[k]=R[j];
                // ans[v[i].second]+=r-j-1;
                k++;
                j++;
            }
        }
        while(i<n1){
            v[k].=L[i];
            i++;
            k++;
        }
        while(j<n2){
            v[k]=R[j];
            j++;
            k++;
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
        return ans;
    }
};