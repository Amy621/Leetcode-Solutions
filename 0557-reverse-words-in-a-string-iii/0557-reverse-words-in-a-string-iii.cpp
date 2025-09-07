class Solution {
public:
    string reverseWords(string s) {
        string ans, tmp;
        int len = s.size();
        reverse(s.begin(), s.end());
        for(int i = len-1; i >= 0; i--){
            if(s[i] == ' '){
                reverse(tmp.begin(), tmp.end());
                ans += tmp;
                ans += ' ';
                tmp = "";
            }
            else tmp += s[i];
        }

        reverse(tmp.begin(), tmp.end());
        ans += tmp;
        return ans;
    }
};