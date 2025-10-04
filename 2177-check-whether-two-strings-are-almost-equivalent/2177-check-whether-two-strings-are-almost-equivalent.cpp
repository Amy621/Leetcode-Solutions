class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
     
     
        vector<int> rm(26, 0), rm1(26, 0);
        for(auto &ch : word1) rm1[ch - 'a']++;
        for(auto &ch : word2) rm[ch - 'a']++;
        
        for(int i = 0; i < 26; i++){
            if(abs(rm1[i] - rm[i]) >= 4) return false;
        }

        return true;


    }
};