class Solution {
public:
    string largestGoodInteger(string num) {
        string s="";
        s = num[0];
        int t = 1;
        string maxi = "";
        int n = num.size();

        for(int i=1;i<n;i++){
            if(num[i]==num[i-1]){
                t++;
                s+=num[i];
                if(t==3){
                    maxi = max(maxi, s);
                }
            }else{
                t=1;
                s = num[i];
            }
        }

        return maxi;
    }
};