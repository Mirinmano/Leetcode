class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2) return {};

        sort(changed.begin(), changed.end());
        unordered_map<int, int> freq;
        for (int x : changed) freq[x]++;

        vector<int> res;
        for (int x : changed) {
            if (freq[x] == 0) continue;
            if (x == 0) {
                if (freq[0] < 2) return {};
                freq[0] -= 2;
                res.push_back(0);
                continue;
            }
            if (freq[2 * x] == 0) return {};
            freq[x]--;
            freq[2 * x]--;
            res.push_back(x);
        }
        return res;
    }
};
