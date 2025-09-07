class Solution {
public:
    string reverseWords(string s) {
        string ans, tmp;
        int len = s.size();
        for(int i = 0; i < len; i++){
            if(s[i] == ' '){
                reverse(tmp.begin(), tmp.end());
                //cout << "tmp: " << tmp << "\n";
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