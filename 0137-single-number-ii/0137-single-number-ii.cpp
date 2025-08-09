class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;

        for(auto i:nums){
            a ^= (i & ~b);
            b ^= (i & ~a);
        }

        return a;
    }
};