class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int r = numBottles;
        int res = r;
        while(r>=numExchange){
            int t = r/numExchange;
            r = r%numExchange + t;
            res += t;
        }

        return res;
    }
};