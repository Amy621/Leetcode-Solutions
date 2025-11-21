class Solution {
public:
    // count how many overlap (end of first interval is bigger than start of
    // second) for each overlap, update the interval to that start, and max end
    // when we find first overlap, then compare end time
    // 3 cases: goes at beginning, middle, end
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ret;
        int len = intervals.size();
        bool found = false, pushed = false;
        vector<int> ans, tmp(2);
        int maxi_end = newInterval[1];
        int maxi_start = newInterval[0];
       
        for (int i = 0; i < len; i++) {
            if(intervals[i][0] >= newInterval[0] && i == 0){
                found = true;
                  ans.push_back(newInterval[0]);
            }
            
            if (!found && intervals[i][1] >= newInterval[0]){
                found = true;
               maxi_start = min(intervals[i][0], newInterval[0]);
               ans.push_back(maxi_start);
                // cout << "start " << intervals[i][0] << "\n";
            }
            

           if (found && intervals[i][0] <= newInterval[1]) {
                maxi_end = max(maxi_end, intervals[i][1]);
                // cout << "end " << maxi_end << "\n";
            }

            else {

                // cout << "here\n";
                if (found && !pushed) {
                    ans.push_back(maxi_end);
                    ret.push_back(ans);
                    pushed = true;
                }
                if (intervals[i][0] != maxi_start &&
                    intervals[i][1] != maxi_end) {
                    tmp[0] = intervals[i][0];
                    tmp[1] = intervals[i][1];
                    //cout << tmp[0] << " " << tmp[1] << "\n";
                    ret.push_back(tmp);
                    //cout << "pushed back" << "\n";
                }
            }
        }
    

    if (ans.size() == 1) {
        ans.push_back(maxi_end);
        ret.push_back(ans);
    }
    if (ans.size() == 0) {
        ans.push_back(newInterval[0]);
        ans.push_back(newInterval[1]);
        ret.push_back(ans);
    }

    return ret;
}
}
;