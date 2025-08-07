class Solution {
public:
    vector<vector<int>> dp;

    int upper(vector<vector<int>>& fruits, int i, int j, int n){
        if(i>=n || j>=n || i<0 || j<=i){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int t = 0;
        for(int k=-1;k<2;k++){
            t = max(t, upper(fruits, i+1, j+k, n));
        }

        return dp[i][j] = t+fruits[i][j];
    }

    int lower(vector<vector<int>>& fruits, int i, int j, int n){
        if(i>=n || j>=n || i<=j || j<0){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int t = 0;
        for(int k=-1;k<2;k++){
            t = max(t, lower(fruits, i+k, j+1, n));
        }

        return dp[i][j] = t+fruits[i][j];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        int a = 0;
        for(int i=0;i<n;i++){
            a += fruits[i][i];
            fruits[i][i] = 0;
        }

        dp.resize(n, vector<int>(n, -1));
        int b = upper(fruits, 0, n-1, n);
        int c = lower(fruits, n-1, 0, n);

        //cout << a << b << c;

        return (a+b+c);
    }
};