// Time complexity: O(nm + n2)
// Intended complexity: O(n + m)
// Notes: instead of the insertion operation, which shifts the array elements to the right, an O(N) operation, we could overwrite the values using a 3 pointer approach.
// Beats 100% of submissions, but a better solution exists.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2,int n) {
         int j = 0;
         int dont = (m+n) - n;
         for(int i = 0; i < n; i++){
           // cout << "In nums1 we are at: " << nums1[j] << " which is iterator: " << j << " and in nums2 we are at: " << nums2[i] << "\n";
            while(nums1[j] < nums2[i]){
             //   cout << nums1[j] << " is less than " << nums2[i] << "\n";
                if(nums1[j] == 0 && j >= dont) break;
                j++;
              //  cout << "iterator j is now: " << j << "\n";
            }
            nums1.insert(nums1.begin() + j, nums2[i]);
          //  cout << "Inserting: " << nums2[i] << " after " << nums1[j] << "\n";
            dont++;
            nums1.pop_back();

         }
    }
};
// 
