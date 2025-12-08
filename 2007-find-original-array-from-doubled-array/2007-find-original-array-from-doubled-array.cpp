class Solution {
public:

// edge cases: contains one 0
//  [2, 3, 6, 6, 12, 4]
// length of input is not divisible by 2
// we need to match smallest to largest
    vector<int> findOriginalArray(vector<int>& changed) {

        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        int len = changed.size();
         
        for(auto &v : changed) mp[v]++;
        
        vector<int> ans;
        if(len % 2 != 0) return ans;
        for(auto &v : changed){
            if(mp[v] == 0) continue; // we already matched this guy
            if(mp[v*2] != 0 && ans.size() < len / 2){
                        if(v * 2 == 0 && mp[v*2] < 2) continue;
                  
                        ans.push_back(v);
                        mp[v*2]--;
                        mp[v]--; // when we match, remove both instances
                    
                }
            }
        


        if(ans.size() != len / 2) ans.clear();
        return ans;

        
        
    }
};