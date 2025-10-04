class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int len = arr.size();

       unordered_map<int, int> mp;

        for(auto &v : arr) mp[v]++;

        vector<int> freqs(len + 1);

        for(auto &p : mp) freqs[p.second]++;

        // k = 5
        // k = 2
        // freq : 3,  (1 1 1, 2 2, 2)
        // k / i
        // 5 / 3 = 1 , remove 1 value of freq 3, (k - (5/ 3) * i)
        // 6 / 3 = 2, remove 2
        int cnt = 0;
        for(int i = 1; i < freqs.size(); i++){
            if(i > k || k == 0) break;
            if(freqs[i] == 0) continue;

            int rems = k / i;
            if(rems == 0) continue;
            int amt = freqs[i];

            if(rems > amt) rems = amt;

            if(k - (rems * i) < 0) break;
            cnt += (rems);
            k -= (rems * i);




        }

        
        return mp.size() - cnt;
    }
};