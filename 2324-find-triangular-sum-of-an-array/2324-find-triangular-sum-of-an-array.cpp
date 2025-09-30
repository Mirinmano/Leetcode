class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        while(nums.size()!=1){
            for(int i=0;i<nums.size()-1;i++){
                temp.push_back((nums[i]+nums[i+1])%10);
            }
            vector<int> t;
            nums=temp;
            temp=t;

        }
        return nums[0];
    }
};