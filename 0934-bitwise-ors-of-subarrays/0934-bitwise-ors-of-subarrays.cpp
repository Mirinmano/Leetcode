class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> total_results;
        unordered_set<int> prev_results;

        for(int x:arr){
            unordered_set<int> current_results;
            current_results.insert(x);
            for(int prev_val:prev_results) {
                current_results.insert(prev_val | x);
            }

            for (int val : current_results) {
                total_results.insert(val);
            }

            prev_results = current_results;
        }

        return total_results.size();
    }
};