class Solution {
public:
    vector<int> dp;

    long change(vector<int>& coins, int a){
        if(a==0) return 0;

        if(a<0) return INT_MAX;

        if(dp[a]!=-1) return dp[a];

        long cnt = INT_MAX;
        for(auto coin:coins){
            cnt = min(cnt, 1+change(coins, a-coin));
        }

        return dp[a]=cnt;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, -1);

        int t = change(coins, amount);

        if(t==INT_MAX){
            return -1;
        }
        return t;
    }
};