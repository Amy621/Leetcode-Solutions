class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), cnt = 0;
        bool seen = false;

        for(int i = len - 1; i >= 0; i--){
            if(s[i] == ' ' && seen) break;
            if(s[i] == ' ' && !seen) continue;
            if(s[i] != ' '){
                seen = true;
                cnt++;
            }   
        }

        return cnt;
    }
};