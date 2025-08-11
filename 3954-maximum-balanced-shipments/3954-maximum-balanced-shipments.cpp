class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n=weight.size();
        int mx=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(weight[i]<mx){
                cnt++;
                mx=INT_MIN;
            }
            else{
                mx=weight[i];
            }
        }
        return cnt;
    }
};