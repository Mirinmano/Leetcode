class Solution {
public:
    vector<vector<double>> dp;

    double helper(int a, int b) {
        if (a <= 0 && b > 0) return 1.0;
        if (a <= 0 && b <= 0) return 0.5;
        if (b <= 0 && a > 0) return 0.0;

        if (dp[a][b] != -1.0) return dp[a][b];

        double prob = 0.25 * (
            helper(a - 4, b) +
            helper(a - 3, b - 1) +
            helper(a - 2, b - 2) +
            helper(a - 1, b - 3)
        );

        return dp[a][b] = prob;
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        n = (n + 24) / 25; // Scale down
        dp.assign(n + 1, vector<double>(n + 1, -1.0));
        return helper(n, n);
    }
};
