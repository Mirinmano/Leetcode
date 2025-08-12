class Solution {
public:
    int n;
    int m;

    vector<vector<int>> vis;
    vector<pair<int, int>> dir={{-1,0},{0,1},{1,0},{0,-1}};

    bool wordSearch(int r, int c,vector<vector<char>>& board, int i, string s){
        if(s.size()==i){
            return true;
        }
        
        if(r<0 || r>=n || c<0 || c>=m || vis[r][c]==1){
            return false;
        }

        vis[r][c]=1;

        if(s[i]==board[r][c]){
            for(auto [x,y]:dir){
                int nx=x+r, ny=y+c;
                if(wordSearch(nx,ny, board, i+1, s)){
                    return true;
                }
            }
        }

        vis[r][c]=0;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vis.resize(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && wordSearch(i,j,board,0,word)) return true;
            }
        }
        return false;
    }
};