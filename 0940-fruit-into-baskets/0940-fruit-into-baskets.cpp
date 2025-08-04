class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        int maxi = 0;
        int j = 0;

        for(int i=0;i<n;i++){
            mp[fruits[i]]++;
            cnt++;

            while(mp.size()>2 && j<i){
                cnt--;
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0){
                    mp.erase(fruits[j]);
                }
                j++;
            }

            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};