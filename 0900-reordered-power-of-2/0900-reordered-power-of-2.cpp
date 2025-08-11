class Solution {
public:
    vector<int> getFre(int num){
        vector<int> freq(10, 0);
        while(num>0){
            freq[num%10]++;
            num/=10;
        }

        return freq;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> valf = getFre(n);

        for(int i=1;i<=1e9;i=i<<1){
            if(valf==getFre(i)){
                return true;
            }
        }

        return false;
    }
};