class Solution {
public:
// When we start at a tree we can only pick from one other tree to the right of it
// longest subarray with at most 2 distinct values
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int cnt = 0, maxi = -1, len = fruits.size(), left = 0, right = 0;
        while (right < len){
            freq[fruits[right]]++;
            

            if(freq.size() > 2){
                maxi = max(cnt, maxi);
                freq[fruits[left]]--;
                cnt--;

                if(freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }

            right++;
            cnt++;
        }

        maxi = max(maxi, cnt);

        return maxi;
    }
};