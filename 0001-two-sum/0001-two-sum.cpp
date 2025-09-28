class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int len = nums.size();
        vector<int> ans;
        for(int i = 0; i < len; i++){

            int v = target - nums[i];

            if(mp.find(v) != mp.end()){
                ans.push_back(mp[v]);
                ans.push_back(i);
                return ans;
            }

            mp[nums[i]] = i;

            
        }

        return ans;
    }
};