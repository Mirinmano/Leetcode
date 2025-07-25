class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        if(maxi<0) return maxi;

        unordered_map<int, int> mp;
        int sum = 0;
        for(auto i:nums){
            mp[i]++;

            if(i>0 && mp[i]==1) sum+=i;
        }

        return sum;
    }
};