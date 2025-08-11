class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long m = 1e9+7;
        vector<long long> pre;
        int t = 1;
        while(n>0){
            if(n&1){
                pre.push_back(t);
            }
            n = n>>1;
            t*=2;
        }

        vector<int> ans;
        for(auto i:queries){
            long long val = 1;
            for(int j=i[0];j<=i[1];j++){
                val *= pre[j];
                val %= m;
            }
            ans.push_back(val);
        }

        return ans;
    }
};