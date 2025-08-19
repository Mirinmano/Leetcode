class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }else{
                res += (1l*cnt*(cnt+1)/2);
                cnt = 0;
            }
        }
        res += (1l*cnt*(cnt+1)/2);

        return res;
    }
};