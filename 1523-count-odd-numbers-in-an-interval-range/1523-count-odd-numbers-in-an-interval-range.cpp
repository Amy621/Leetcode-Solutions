class Solution {
public:
// odd numbers alternate, if our length is even then regardless of start or end its half
// if our length is odd:
// 2 3 4, 3 / 2 = 1
// 3 4 5, it ends in odd so 3 / 2 = 1 + 1 = 2
// 2 3 4 
    int countOdds(int low, int high) {
        int cnt = high - low + 1;
      
        if(cnt % 2 != 0){
            if(high % 2 == 0) return cnt / 2;
            else return (cnt / 2) + 1;
        }
        return cnt / 2;
    }
};