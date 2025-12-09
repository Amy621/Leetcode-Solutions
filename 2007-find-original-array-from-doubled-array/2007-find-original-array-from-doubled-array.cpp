class Solution {
public:

// edge cases: contains one 0
//  [2, 3, 6, 6, 12, 4]
// length of input is not divisible by 2
// we need to match smallest to largest
    vector<int> findOriginalArray(vector<int>& changed) {

        //sort(changed.begin(), changed.end());

        vector<int> freq(100001, 0);

        unordered_map<int, int> mp;
        int len = changed.size();
         
        for(auto &v : changed) mp[v]++;
        
        vector<int> ans;
        if(len % 2 != 0) return ans;

        for(int i = 0; i < 100001; i++){
           while(mp[i] > 0){
                if (i == 0) {
                    if (mp[0] < 2) break;
                    ans.push_back(0);
                    mp[0] -= 2;
                    continue;
                }
                
                if (mp[2 * i] <= 0) break;

                ans.push_back(i);
                mp[i]--;
                mp[2 * i]--;
            }
        }

       
            if(ans.size() != len / 2) ans.clear();
            return ans;

            
        
    }
};