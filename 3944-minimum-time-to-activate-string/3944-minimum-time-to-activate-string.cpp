class Solution {
public:
    bool isValid(string s, int k){
        int n = s.size();
        long long tot = 1l*n*(n+1)/2;

        int l = 0;
        long long w = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                w += 1l*l*(l+1)/2;
                l=0;
            }else{
                l++;
            }
        }
        w += 1l*l*(l+1)/2;
        //cout << tot << ' ' << w << endl;
        return (tot-w)>=k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int r = order.size();
        int l = 1;
        int res;
        int mid;

        if(k>(1l*r*(r+1)/2)) return -1;

        while(l<=r){
            int mid = l+(r-l)/2;
            string temp = s;
            for(int i=0;i<mid;i++){
                temp[order[i]]='*';
            }
            //cout << mid << ' ' << temp << endl;
            if(isValid(temp, k)){
                res = mid-1;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return res;
    }
};