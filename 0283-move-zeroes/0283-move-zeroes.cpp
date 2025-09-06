class Solution {
public:
// maintain left and right pointer. when we hit a 0, place left pointer there. move 
// right pointer to the next non-zero element. then, swap. move left pointer.
// when right pointer reaches len, we stop

    void moveZeroes(vector<int>& nums) {
        int len = nums.size();

        int left = 0;
     
        for (int right = 0; right < len; right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
            
             
    }
};