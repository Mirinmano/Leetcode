class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pf, sf;
        int n = s.size();
        int m = p.size();

        for(int i=0;i<m;i++){
            pf[p[i]]++;
            sf[s[i]]++;
        }

        vector<int> res;
        if(sf==pf){
            res.push_back(0);
        }

        for(int i=m;i<n;i++){
            sf[s[i]]++;
            sf[s[i-m]]--;

            if(sf[s[i-m]]==0) sf.erase(s[i-m]);

            if(sf==pf){
                res.push_back(i-m+1);
            }
        }

        return res;
    }
};