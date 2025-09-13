class Solution {
public:
    int maxFreqSum(string s) {
        unordered_set<int> st = {'a', 'e', 'i', 'o', 'u'};
        int maxv = 0;
        int maxc = 0;
        unordered_map<char, int> mp;

        for(auto i:s){
            mp[i]++;
            if(st.find(i)!=st.end()){
                maxv = max(maxv, mp[i]);
            }else{
                maxc = max(maxc, mp[i]);
            }
        }

        return maxv+maxc;
    }
};