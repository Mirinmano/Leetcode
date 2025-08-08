class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        if(n<=3) return false;
        for(int i=1;i<n;i++){
            if(cnt%2==0 && nums[i-1]>=nums[i]){
                if(i-1==0 || nums[i-1]==nums[i]) return false;
                cnt++;
            }else if(cnt%2!=0 && nums[i-1]<=nums[i]){
                if(nums[i-1]==nums[i]) return false;
                cnt++;
            }
        }

        return cnt==2;
    }
};