class Solution {
public:
    using t = tuple<int, int, int>;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if(m<3 || n<3) return 0;

        priority_queue<t, vector<t>, greater<t>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0;i<n;i++){
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][m-1], i, m-1});
            vis[i][0] = vis[i][m-1] = true;
        }
        for(int i=1;i<m-1;i++){
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[n-1][i], n-1, i});
            vis[0][i] = vis[n-1][i] = true;
        }

        vector<pair<int, int>> dir={{0,1}, {1,0}, {0,-1}, {-1,0}};

        int unit = 0;
        int m_h = 0;
        while(!pq.empty()){
            auto [h, x, y] = pq.top();
            pq.pop();
            m_h = max(m_h, h);

            for(auto [a, b]:dir){
                int nx=x+a, ny=y+b;
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    vis[nx][ny]=true;
                    if(heightMap[nx][ny]<m_h){
                        unit+=m_h-heightMap[nx][ny];
                    }
                    pq.push({heightMap[nx][ny], nx, ny});
                }
            }
        }
        return unit;
    }
};