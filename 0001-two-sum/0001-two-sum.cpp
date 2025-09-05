class Solution {
public:
// go through list, insert into map
// go through list second time, if target - cur is in the map, return true
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, unordered_set<int>> mp;
        int len = nums.size();
        vector<int> ans;
        for(int i = 0; i < len; i++) mp[nums[i]].insert(i);
        
        for(int i = 0; i < len; i++){
            mp[nums[i]].erase(i);
            int cur = target - nums[i];
            if(mp[cur].size() >= 1){
                ans.push_back(i);
                int ret = *mp[cur].begin();
                ans.push_back(ret);
                break;
            }
            mp[nums[i]].insert(i);
        }

        return ans;
    }
};