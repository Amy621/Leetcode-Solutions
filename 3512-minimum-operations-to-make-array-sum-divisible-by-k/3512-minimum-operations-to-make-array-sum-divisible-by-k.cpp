class Solution {
public:
// if the sum is less than d, then the sum must be 0
// if the sum is greater than d, in order to be divisible it must be equal to
// the multiple of d before it
// ex: k = 3, sum = 19, 19 / 3 = 6 R 1, so remove 1
// k = 7, sum = 25, 25 / 7 = 3 R 4, so remove 4
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &v : nums) sum += v;
        return (sum % k);
    }
};