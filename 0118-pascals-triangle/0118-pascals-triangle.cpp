class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt(numRows);

        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    pt[i].push_back(1);
                }else{
                    pt[i].push_back(pt[i-1][j-1]+pt[i-1][j]);
                }
            }
        }

        return pt;
    }
};