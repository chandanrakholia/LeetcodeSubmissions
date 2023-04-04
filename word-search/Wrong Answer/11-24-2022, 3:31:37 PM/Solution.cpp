// https://leetcode.com/problems/word-search

class Solution {
public:
bool bfs(vector<vector<char>>& board,int i,int j,string word){
    // cout<<"checked"<<endl;
    int m=board.size();int n=board[0].size();
    vector<vector<int>> visited(m,vector<int> (n,-1));
    queue<vector<int>>q;
    int c=0;
    q.push({i,j,word[c]});
    while(!q.empty()){
        vector<int> t=q.front();
        q.pop();
        int x=t[0];
        int y=t[1];
        char z=t[2];
        // cout<<"checked"<<endl;
        // cout<<z<<endl;
        if(x<0 || x>=m || y<0 || y>=n || board[x][y]!=z){continue;}
        if(visited[x][y]!=-1){
                continue;
        }
        // cout<<board[x][y]<<' '<<z<<endl;
        // cout<<c<<endl;
        cout<<x<<' '<<y<<endl;
        if(board[x][y]==z and c==word.length()-1){
            return true;
        }
        visited[x][y]=1;
        c++;
        if(c==word.length()){
            break;
        }
        q.push({x+1,y,word[c]});
        q.push({x-1,y,word[c]});
        q.push({x,y+1,word[c]});
        q.push({x,y-1,word[c]});
    }
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();int n=board[0].size();
        bool k=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    k=k || bfs(board,i,j,word);
                }
            }
        }
        return k;
    }
};