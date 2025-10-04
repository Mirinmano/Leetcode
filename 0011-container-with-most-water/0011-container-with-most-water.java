class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length - 1;
        int max1 = 0;
        while (l < r) {
            int x = Math.min(height[l], height[r]) * (r - l);
            max1 = Math.max(max1, x);
            if (height[l] < height[r]) {
                l++;
            }    else {
                r--;
            }
        }
        return max1;
    }
}