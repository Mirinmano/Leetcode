class Solution {
public:
    int countAsterisks(string s) {
        int t = 0;
        int res = 0;

        for(auto i:s){
            if(t%2==0 && i=='*'){
                res++;
            }

            if(i=='|') t++;
        }

        return res;
    }
};