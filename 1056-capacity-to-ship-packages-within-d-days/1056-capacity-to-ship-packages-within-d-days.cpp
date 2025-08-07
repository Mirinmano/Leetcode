class Solution {
public:
    bool valid(vector<int>& w, int d, int maxi){
        int n = w.size();
        int t = 1;
        int tsum = 0;
        for(int i=0;i<n;i++){
            if(w[i]>maxi){
                return false;
            }

            if(tsum+w[i]<=maxi){
                tsum+=w[i];
            }else{
                tsum = w[i];
                t++;
            }
        }

        if(t<=d) return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int h = 0;
        for(auto i:weights){
            h +=i;
        }

        int l = 0;
        int res;

        while(l<=h){
            int mid = l+(h-l)/2;

            if(valid(weights, days, mid)){
                res = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        return res;
    }
};