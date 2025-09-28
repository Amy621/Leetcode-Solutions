class Solution {
public:
// we want to remove numbers who have the smallest frequencies
// Place by frequencies, then insert into our set the nums per frequency
// Multiply freq times size of our set to get how many removals we make
// Keep a track of how many removals we have left
// so each time we remove, it will be based on freq * size of set, decrement from k
// if removal size is less than current freq, we break early
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      //  cout << arr.size();
        unordered_map<int, int> mp;
        int len = arr.size();
        for(auto &v : arr) mp[v]++;
        // place by frequencies, freq 1: size, freq 2: size

        vector<unordered_set<int>> freq(len + 1);
   
        for(auto &p : mp){
            freq[p.second].insert(p.first);
          //  cout << "freq: " << p.second << " number: " << p.first << "\n";
        }

        // we stop early if the frequency is bigger than k
        // for frequencies of 1, we check the size
        // 2 3 4 with frequency of 1 means 3 removals
        // 2 with frequency of 2 moves 2 removsals
        // 4 with frequency of 3 means 3 removals
        // so, 3 * size
        //  3 * 1  = 3 removals
        // 4, 5 with freq 3 means 6 removals
        // 3 * 2 = 6 removals

        int sz = 0, rem_left = k; 
 //cout << "unique numbs size: " << mp.size() << "\n";  
        // cnt is removals we made, sz is how many unique numbers we have
        // if we successfully remove all values in our set, then sz = size of set
        for(int it = 1; it < freq.size(); it++){
         // if(it > k || rem_left <= 0) break;
       
          if(freq[it].size() != 0){
           // cout << freq[it].size() << " freq: " << it << "\n";
            int removals = (freq[it].size() * it);
            if(removals > rem_left){
                int rm = rem_left / it; // 5 / 2
                sz += rm;
              //  cnt += rm;
              //  cout << "count is: " << cnt << "\n";
        // cout << "left is: " << rem_left  << "\n";
                break;

            }
            // what if we have k = 5
            // freq: 2, (3, 4, 5)
            // 6 removals, but we can remove 2 numbers
            // 5 / it = 2 
            // k = 3
            // 1, 1, 2
            // k = 2, freq: 1, 1, 1, 2, 2, 2, 2, 2
            // 3, 3, 3, 4, 4, 4, 5, 5, 5
            // k = 8
            else //cnt += (freq[it].size() * it); 
            sz += freq[it].size();
            rem_left -= (removals);
           // cout << "count is: " << cnt << "\n";
     //    cout << "left is: " << rem_left  << "\n";
          }
          //if(cnt == k) break;
        
        }


        
        int tot = mp.size();
        //cout << sz << "\n";
        int ans = tot - sz;
        if(ans <= 0) return 0;
        return (tot - sz);
    }
};