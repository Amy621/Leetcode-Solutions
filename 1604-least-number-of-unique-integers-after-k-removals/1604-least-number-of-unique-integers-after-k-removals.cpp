class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int len = arr.size();

       map<int, int> mp;

        for(auto &v : arr) mp[v]++;

        vector<vector<int>> freqs(len + 1);

        for(auto &p : mp) freqs[p.second].push_back(p.first);
       
        for(int i = 1; i < freqs.size(); i++){
            if(i > k) break;
            for(auto &v : freqs[i]){
                if (k == 0) break;
                if(k - i < 0) break;
                k -= i;
                mp.erase(v);
            
            }
        }

        
        return mp.size();
    }
};