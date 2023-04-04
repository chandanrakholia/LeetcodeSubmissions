// https://leetcode.com/problems/minimum-genetic-mutation

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        unordered_map<string,int> vis;
        q.push(start);
        vis[start]=1;
        int step=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string s=q.front();
                q.pop();
                if(s==end) return step;
                for(int j=0;j<8;j++){
                    char oc=s[j];
                    for(int k=0;k<4;k++){
                        s[j]="ACGT"[k];
                        if(!vis[s] && find(bank.begin(),bank.end(),s)!=bank.end()){
                            q.push(s);
                            vis[s]=1;
                        }
                        s[j]=oc;
                    }
                }
                step+=1;
            }
        }
        return -1;
    }
};