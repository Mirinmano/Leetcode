class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        int cnt = 0;

        string s;
        while(getline(ss, s, ' ')){
            int fl=1;
            for(auto i:brokenLetters){
                if(s.find(i)!=string::npos){
                    fl=0;
                    break;
                }
            }

            if(fl) cnt++;
        }

        return cnt;
    }
};