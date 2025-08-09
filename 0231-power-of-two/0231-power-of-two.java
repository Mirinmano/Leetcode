class Solution {
    public boolean p(int n,int l,int h){
        if(l<=h){
            int mid = (int)l+(h-l)/2;
            int val = (int)Math.pow(2,mid);
            if(val == n){
                return true;
            }
            else if(val>n){
                return p(n,0,mid-1);
            }
            else if(val<n){
                return p(n,mid+1,h);
            }
            return false;
        }
        return false;
    }
    public boolean isPowerOfTwo(int n) {
        if(2147483647==n)
            return false;
        return p(n,0,n/2);
    }
}