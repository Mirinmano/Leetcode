class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int st=0,ed=matrix.size()-1;
        int en=ed;
        while(st<ed){
            for(int i=st;i<ed;i++){
                int t = matrix[en-i][st];
                //cout<<matrix[en-i][st]<<' '<< matrix[ed][en-i]<<' '<< matrix[i][ed]<<' '<< matrix[st][i]<<endl;
                matrix[en-i][st]=matrix[ed][en-i];
                matrix[ed][en-i]=matrix[i][ed];
                matrix[i][ed]=matrix[st][i];
                matrix[st][i]=t;
                //cout<<matrix[ed-i][st]<<' '<< matrix[ed][ed-i]<<' '<< matrix[i][ed]<<' '<< matrix[st][i]<<endl;
            }
            st++;
            ed--;
        }
    }
};