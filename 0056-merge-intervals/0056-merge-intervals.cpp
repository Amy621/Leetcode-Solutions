class Solution {
public:

// sort the intervals based on start times
// then, check if end time of first interval is bigger than start time of second interval
// if it is, then new end = that intervals end
// push back once we get against
  
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int len = intervals.size();

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        vector<int> ans(2);
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < len; i++){
         //   cout << intervals[i][0] << " " << intervals[i][1] << "\n";
          //  cout << start << " " << end << "\n";
            if(end >= intervals[i][0]){
                end = max(intervals[i][1], end);
              //  cout << start << " " << end << "\n";
            }

            else{
             //   cout << start << " " << end << "\n";
               // vector<int> ans(2);
                ans[0] = start;
                ans[1] = end;
                ret.push_back(ans);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        
      //  vector<int> ans(2);
        ans[0] = start;
        ans[1] = end;
        ret.push_back(ans);
        return ret;
    }
        

      
};