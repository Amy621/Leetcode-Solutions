class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<multiset<int>> ans(15);

        for(auto &v : arr){
            int key = __builtin_popcount(v);
            ans[key].insert(v);
        }

        vector<int> ret;

        for(int i = 0; i < 15; i++){
            for(auto &v : ans[i]) ret.push_back(v);
        }

        return ret;
        
    }
};