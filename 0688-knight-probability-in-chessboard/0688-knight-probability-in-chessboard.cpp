class Solution {
public:
    vector<pair<int, int>> dir = {{2, -1}, {2, 1}, {-2, -1}, {-2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

    vector<vector<vector<double>>> dp;

    double helper(int i, int j, int k, int n){
        if(i<0 || i>=n || j<0 || j>=n){
            return 0;
        }

        if(k==0) return 1;

        if(dp[i][j][k]!=-1.0){
            return dp[i][j][k];
        }

        double rate = 0;
        for(auto [x, y]:dir){
            rate += 0.125 * helper(i+x, j+y, k-1, n);
        }

        return dp[i][j][k] = rate;
    }

    double knightProbability(int n, int k, int row, int column) {
        dp.resize(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return helper(row, column, k, n);
    }
};