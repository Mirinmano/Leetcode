class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        auto t = stoll(s);
        if(t>INT_MAX || t<=n) return -1;

        return t;
    }
};