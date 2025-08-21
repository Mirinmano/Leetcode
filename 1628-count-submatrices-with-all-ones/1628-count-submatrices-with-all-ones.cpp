class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int rc = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1 && i > 0) {
                    mat[i][j] += mat[i-1][j];
                }
            }

            for (int j=0;j<m;j++){
                int minHeight = mat[i][j];
                for(int k=j;k>=0 && minHeight>0;k--) {
                    minHeight = min(minHeight, mat[i][k]);
                    rc += minHeight;
                }
            }
        }

        return rc;
    }
};