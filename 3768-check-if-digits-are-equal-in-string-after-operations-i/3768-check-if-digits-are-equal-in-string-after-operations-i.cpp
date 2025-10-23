class Solution {
public:
    bool hasSameDigits(string s) {
        int len = s.size();
        string cur = "";
        string tmp = s;
        while(cur.size() != 2){
            if(cur.size() != 0){
                tmp = cur;
                cur = "";
                len = tmp.size();
            }
            for(int i = 0; i < len - 1; i++){
                int v1 = (tmp[i] - '0');
                int v2 = (tmp[i + 1] - '0');
                cur += to_string((v1 + v2) % 10);
            }
        }

        
      
        return(cur[0] == cur[1]);
    }
};