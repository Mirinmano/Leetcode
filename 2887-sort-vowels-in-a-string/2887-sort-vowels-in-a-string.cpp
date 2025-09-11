class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string t = "";
        for(auto i:s){
            if(st.find(i)!=st.end()){
                t+=i;
            }
        }

        int k = 0;
        sort(t.begin(), t.end());
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end()){
                s[i] = t[k++];
            }
        }

        return s;
    }
};