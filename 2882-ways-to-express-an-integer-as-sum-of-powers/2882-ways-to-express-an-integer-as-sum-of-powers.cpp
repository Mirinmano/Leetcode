class Solution {
public:
    vector<vector<int>> dp;
    const int MOD = 1e9+7;

    int helper(int n, int x, int i){   
        if(n<0 || i<1) return 0;
        if(n<=1) return 1;

        if(dp[n][i]!=-1) return dp[n][i];

        long long t = helper(n-int(pow(i, x)), x, i-1);
        long long nt = helper(n, x, i-1);

        return dp[n][i] = (t+nt)%MOD;
    }

    int numberOfWays(int n, int x) {
        int m = ceil(pow(n, 1.0/x));
        dp.assign(n+1, vector<int>(m+1, -1));
        return helper(n, x, m);
    }
};