class Solution {
public:
// longest substring means sliding window technique
//  unordered set
// insert each string into the map
// when we reach a collision into the set, we save the string with the longest current length
// then, we delete the beginning character of the string and slide our window
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int len = s.size(), right = 0, maxi = 0;
        string cur = "";
        while(right < len){ 
            //cout << cur << "\n";
                if(mp.count(s[right]) > 0 && cur.size() > 0){
                    //cout << "cur idx: " << right << "\n";
                    if(maxi  < cur.size()) maxi = cur.size();
                    auto it = cur.begin();
                    mp.erase(*it);
                    cur.erase(0, 1);                    
                   
                }
                else{
                    mp.insert(s[right]);
                    cur += s[right];
                    right++;
                }
                if(maxi < cur.size()) maxi = cur.size();
               
            }
            //cout << cur << "\n";
            return maxi;
        }
    
};