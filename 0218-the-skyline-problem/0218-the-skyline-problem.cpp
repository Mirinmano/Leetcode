class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        vector<vector<int>> res;

        int n  = buildings.size();
        for(int i=0;i<n;i++){
            events.push_back({buildings[i][0], i});
            events.push_back({buildings[i][1], i});
        }

        sort(events.begin(), events.end());
        priority_queue<pair<int, int>> pq;

        int i=0;
        n = events.size();
        while(i<n){
            auto [e, in] = events[i];

            while(i<n && e==events[i].first){
                int t = events[i].second;

                if(buildings[t][0]==e){
                    pq.push({buildings[t][2], buildings[t][1]});
                }
                i++;
            }

            while(!pq.empty() && pq.top().second<=e) pq.pop();

            int h = pq.empty()?0:pq.top().first;
            if(res.empty() || res.back()[1]!=h){
                res.push_back({e, h});
            }
        }

        return res;
    }
};