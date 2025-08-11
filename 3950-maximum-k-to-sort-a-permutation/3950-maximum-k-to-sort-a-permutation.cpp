class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        bool is = true;
        for(int i=0;i<n;i++){
            if(i!=nums[i]){
                is = false;
                res &= nums[i];
            }
        }

        if(is) return 0;
        return res;
    }
};
