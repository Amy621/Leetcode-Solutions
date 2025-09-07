class Solution {
public:
// We can build the reverse number up by tak
typedef long long ll;
    bool isPalindrome(int x) {
        ll reverse = 0, tmp = x;
        if(x < 0) return false;
        while(tmp != 0){
            ll r  = tmp % 10;
            reverse = reverse * 10 + r;
            tmp /= 10;

        }

        if(reverse == x) return true;
        return false;
    }
};