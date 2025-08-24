class Solution {
public:
// longest subarray where 0 only appears one time
// 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1
// When we encounter a 0, we insert the previous 0 back in, and all numbers before previous 0 get taken out
// then we slide our left pointer to begin at the next 0
// [0,1,1,1,0,1,1,0,1]
// Numbers before 0: 0
// set previous to idx 0 and prev_cnt to 0
// count up to next 0: 3
// 3 - 0 = 3
// set prev to idx 4 and prev_cnt to 3
// count up to next 0: 5
// 5 - 3 = 2
// set prev to idx 7 and prev_cnt to 2
// cout to end is equal to 3

    int longestSubarray(vector<int>& nums) {
        int len = nums.size(), left = 0, right = 0, maxi = 0, cnt = 0, prev_idx = -1, prev_cnt = 0;
        bool seen = false;

        while(right < len){
            if(nums[right] == 0 && seen == false){
                prev_idx = right;
                cnt -= prev_cnt;
                prev_cnt = cnt;
                seen = true;
            }
            else if(nums[right] == 0 && seen == true){
                maxi = max(maxi, cnt);
                int tmp = cnt - prev_cnt;
                prev_cnt = tmp;
                cnt = tmp;
                prev_idx = right;
               
            }
            else if(nums[right] == 1) cnt++;
            
            right++;
           // cout << "count of 1s before idx " << prev_idx << " is " << prev_cnt << "\n";
           // cout << "the current count is " << cnt << "\n";
        }
        maxi = max(maxi, cnt);
        if(seen == false) maxi--;
        return maxi;


        }
    
};