class Solution {
public:
    bool valid(vector<int>& q, int maxi, int m){
        int cnt = 0;
        int cur = 0;
        int n = q.size();

        for(int i=0;i<n;i++){
            cnt+=(q[i]/maxi);
            if(q[i]%maxi!=0) cnt++;
        }

        //cout << cnt << endl;
        if(cnt>m) return false;
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int h = 10000000;
        int l = 1;
        int mid;
        int ans;

        while(l<=h){
            mid = l+(h-l)/2;
            //cout << l << ' ' << mid << ' ' << h << endl;
            if(valid(quantities, mid, n)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};