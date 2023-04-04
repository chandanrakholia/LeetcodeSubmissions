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
        if(x<0 || x>=m || y<0 || y>=n){continue;}
        if(visited[x][y]!=-1){
                continue;
        }
        // cout<<board[x][y]<<' '<<z<<endl;
        // cout<<c<<endl;
        if(board[x][y]==z and c==word.length()-1){
            return true;
        }
        if(board[x][y]!=z){
            visited[x][y]=-1;
            continue;
        }
        else{
            visited[x][y]=1;
        }
        c++;
        if(c==word.length()){
            break;
        }
        cout<<x<<' '<<y<<endl;
        q.push({x+1,y,word[c]});
        q.push({x-1,y,word[c]});
        q.push({x,y+1,word[c]});
        q.push({x,y-1,word[c]});
    }
    return false;
}
bool dfs(int i,int j,int count,vector<vector<char>>& board, string word){
    if(word.length()==count) return true;
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[count]) return false;
    char temp =board[i][j];
    board[i][j]=' ';
    bool ans=dfs(i+1,j,count+1,board,word) || dfs(i-1,j,count+1,board,word) || dfs(i,j+1,count+1,board,word) || dfs(i,j-1,count+1,board,word);
    board[i][j]=temp;
    return ans;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();int n=board[0].size();
        bool k=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] and dfs(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};