// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze

class Solution {
public:
    int visited[101][101]={0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row=maze.size();
        int col=maze[0].size();
        // cout<<"row="<<row<<" col="<<col<<endl;
        visited[entrance[0]][entrance[1]]=1;
        queue<vector<int>>q;
        int step=0;
        q.push({entrance[0],entrance[1],step});
        while(!q.empty()){
            vector<int> t=q.front();
            q.pop();
            int x=t[0];
            int y=t[1];
            // cout<<"x= "<<x<<" y="<<y<<endl;
            if(x<0 || x>=row || y<0 || y>=col){
                // cout<<"if1"<<endl;
                continue;
            }
            if(maze[x][y]=='+') { continue;}
            visited[x][y]=1;
            if((x==0 || y==0 || x==row-1 || y==col-1) && ((x!=entrance[0]) || (y!=entrance[1]))){
                // cout<<"checked"<<endl;
                // cout<<x<<' '<<y<<endl;
                return t[2];
            }
            if(visited[x][y]!=0 && x!=entrance[0] && y!=entrance[1]){
                // cout<<"if3"<<endl;
                continue;
            }
            q.push({x+1,y,t[2]+1});
            q.push({x-1,y,t[2]+1});
            q.push({x,y+1,t[2]+1});
            q.push({x,y-1,t[2]+1});
        }
        return -1;
    }
};