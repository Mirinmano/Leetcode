class Solution {
public:
    vector<string> com;

    void backtrack(string s, int n){
        //cout << s << endl;
        if(s.size()==n){
            com.push_back(s);
            return;
        }

        string t = s;
        for(char i='a';i<='c';i++){
            if(s[s.size()-1]!=i){
                t+=i;
                backtrack(t, n);
                t=s;
            }
        }
    }

    string getHappyString(int n, int k) {

        for(char i='a';i<='c';i++){
            string t = "";
            t+=i;
            //cout << t;
            backtrack( t, n);
        }

        if(com.size()<k) return "";

        return com[k-1];
    }
};