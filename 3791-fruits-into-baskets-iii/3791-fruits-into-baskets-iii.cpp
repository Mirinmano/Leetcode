class Solution {
public:
    vector<int> tree;

    void build(vector<int>& bt, int idx, int l, int h){
        if(l==h){
            tree[idx] = bt[l];
            return;
        }

        int mid = l+(h-l)/2;
        build(bt, idx*2, l, mid);
        build(bt, idx*2+1, mid+1, h);
        tree[idx] = max(tree[idx*2], tree[idx*2+1]);
    }

    int find(int idx, int l, int h, int ft){
        if(tree[idx]<ft){
            return -1;
        }

        if(l==h){
            tree[idx] = -1;
            return l;
        }

        int mid = l+(h-l)/2;
        int res;
        if(tree[idx*2]>=ft){
            res = find(idx*2, l, mid, ft);
        }else{
            res = find(idx*2+1, mid+1, h, ft);
        }
        tree[idx] = max(tree[idx*2], tree[idx*2+1]);
        return res;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        tree.resize(4*n, 0);
        build(baskets, 1, 0, n-1);

        int up = 0;
        for(auto i:fruits){
            if(find(1, 0, n-1, i)==-1) up++;
        }

        return up;
    }
};