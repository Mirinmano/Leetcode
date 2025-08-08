class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(auto i:nums){
            x^=i;
        }

        x &= -x;
        int a = 0, b = 0;
        for(auto i:nums){
            if(i&x) a^=i;
            else b^=i;
        }

        return {a, b};
    }
};