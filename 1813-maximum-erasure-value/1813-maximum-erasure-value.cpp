class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        int maxi = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            mp[nums[i]]++;

            while(mp[nums[i]]>1){
                sum -= nums[j];
                mp[nums[j++]]--;
            }

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};