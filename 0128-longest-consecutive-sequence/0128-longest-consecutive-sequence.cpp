class Solution {
public:
    // 
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> a;
        for(auto &v : nums) a.insert(v);

        int maxi = -1;
        int cnt = 1;
        for(auto it = a.begin(); it != prev(a.end()); it++){
           
            int v = *it;
            auto it2 = it;
            it2++;
            int v2 = *it2;
           // cout << v << " " << v2 << "\n";
            if(abs(v - v2) == 1) cnt++;
            else{
                maxi = max(cnt, maxi);
                cnt = 1;
            }
          
        }
        maxi = max(cnt, maxi);
        return maxi;
    }
};
