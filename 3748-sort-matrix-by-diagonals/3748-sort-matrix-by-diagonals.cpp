class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int d=0;d<n;d++){
            vector<int> dg;
            int i = d, j = 0;
            while(i<n && j<n){
                dg.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(dg.rbegin(), dg.rend()); 
            i = d, j = 0;
            int idx = 0;
            while(i<n && j<n){
                grid[i][j] = dg[idx++];
                i++;
                j++;
            }
        }
        
        for(int d=1;d<n;d++){
            vector<int> dg;
            int i = 0, j = d;
            while(i<n && j<n){
                dg.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(dg.begin(), dg.end()); 
            i = 0, j = d;
            int idx = 0;
            while(i<n && j<n) {
                grid[i][j] = dg[idx++];
                i++;
                j++;
            }
        }
        
        return grid;
    }
};