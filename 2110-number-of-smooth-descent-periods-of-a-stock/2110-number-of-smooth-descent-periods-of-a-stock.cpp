class Solution {
public:
// have a list that stores differences between adjacent values, then count all streaks of ones

// (n(n + 1) / 2)
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt = 0, len = prices.size(), strk = 0;

        vector<int> ans(len, 0);

        cnt += len;

        for(int i = 1; i < len; i++){
            ans[i - 1] = prices[i - 1] - prices[i];
            //cout << ans[i - 1] << " ";
        }

        //cout << "\n";

        for(int i = 0; i < len; i++){
            if(ans[i] == 1){
                
                strk++;
            }

            else{
                cnt += (strk * (strk + 1)) / 2;
              
                strk = 0;
            }
        }

        return cnt;
    }
};