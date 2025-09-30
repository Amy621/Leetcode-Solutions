 class Solution {
public:
// save indices of beginning brackets, then for a mismatch we clear and save the ending
    int longestValidParentheses(string s) {
        int len = s.size(), end_string = -1, maxi = 0;

        map<char, vector<int>> mp; // store indices
        stack<char> s1;  

        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                s1.push(s[i]);
                mp[s[i]].push_back(i); // push opening placement
          
            } else {
                if (s1.empty()) {
                    mp.clear();
                    end_string = i;  // beginning of unmatched closing
                    continue;
                }

                char ch = s1.top();
           
                if (s[i] == ')' && ch != '(') {
                    while (!s1.empty()) s1.pop(); // discard and start at beginning of unmatched closing
                    mp.clear();
                   
                    end_string = i;
                    continue;
                
            }
              
                s1.pop(); // matched
               
                mp['('].pop_back(); // delete it

                int cur;
                if (s1.empty()) { // fully matched substring
                    cur = i - end_string;  // distance from closed
                } else {
                    cur = i - mp['('].back(); // distance from last unmatched opening
                }

               
                maxi = max(maxi, cur);
            }
        }
        

          

        return maxi;
    }

       
    
};

