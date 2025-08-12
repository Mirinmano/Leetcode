class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    vector<int> powers;

    int helper(int n, int i) {
        if (n == 0) return 1;   // found a valid way
        if (n < 0 || i < 1) return 0;

        if (dp[n][i] != -1) return dp[n][i];

        long long take = 0;
        if (powers[i] <= n) take = helper(n - powers[i], i - 1);
        long long skip = helper(n, i - 1);

        return dp[n][i] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        int m = ceil(pow(n, 1.0 / x)); 
        dp.assign(n + 1, vector<int>(m + 1, -1));

        powers.resize(m + 1);
        for (int i = 1; i <= m; i++) {
            long long p = 1;
            for (int j = 0; j < x; j++) p *= i;
            powers[i] = (int)p;
        }

        return helper(n, m);
    }
};
