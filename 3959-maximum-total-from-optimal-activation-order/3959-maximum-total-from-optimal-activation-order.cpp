class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = limit.size();
        vector<pair<int,int>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({limit[i], value[i]});
        }
        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        int i = 0, j = 0;
        long long val = 0;
        while (i < n) {
            val += p[i].second;
            i++;
            int active = i - j;
            while (j < n && p[j].first <= active) {
                j++;
            }
            while (j > i) {
                i++;
            }
        }
        return val;
    }
};
