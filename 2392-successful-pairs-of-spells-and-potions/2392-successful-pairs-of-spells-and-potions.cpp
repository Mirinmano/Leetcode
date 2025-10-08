class Solution {
public:
    int bs(vector<int>& potions, long long s, int l, int h, int mul){
        if(l<h){
            int mid = l+(h-l)/2;
            
            if(1l*potions[mid]*mul<s){
                return bs(potions, s, mid+1, h, mul);
            }else{
                return bs(potions, s, l, mid, mul);
            }
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int l = bs(potions, success, 0, potions.size(), spells[i]);
            res.push_back(potions.size()-l);
        }
        return res;
    }
};