#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n = changed.size();
        if (n % 2 != 0) return {};   
        
        int mid = n / 2;
        vector<int> res(mid);
        

        const int MAXV = 100000;
        vector<int> freq(MAXV + 1, 0);
        
        for (int x : changed) {
            if (x > MAXV) return {};  
            freq[x]++;
        }
        
        int idx = 0;
        
     
        for (int no = 0; no <= MAXV; no++) {
            while (freq[no] > 0 && no * 2 <= MAXV && freq[no * 2] > 0) {
                freq[no]--;
                freq[no * 2]--;
                res[idx++] = no;
            }
        }
        
  
        for (int i = 0; i <= MAXV; i++) {
            if (freq[i] != 0) {
                return {};
            }
        }
        
        return res;
    }
};
