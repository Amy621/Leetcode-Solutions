class Solution {
public:
    
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 != 0) return false;

        stack<char> s1;

        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') s1.push(s[i]); // top will be the latest occurence of opening 
            else{
                if(s1.empty()) return false;
                char ch = s1.top();  // then, we just check if the first closing we see corresponds to the most recent opening
                if(s[i] == ']' && ch != '[') return false;
                if(s[i] == ')' && ch != '(') return false;
                if(s[i] == '}' && ch != '{') return false;
                s1.pop();
            }
            
           
        }
        
        if(!s1.empty()) return false;
        return true;
    }
};