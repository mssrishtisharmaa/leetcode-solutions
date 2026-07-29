class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n = nums.size();
        int len =0 ;
        int maxlen = 0;
        int l = 0;
        int r = 0;
        int zero = 0;


        while(r < n){
            //update count
            if(nums[r] == 0) zero++;

            // shrink (invalid)
            if(zero > k){
                if(nums[l] ==0) zero--;

                l++;
            }

            //valid
            if(zero <= k){
                len = r - l +1;
                maxlen = max(maxlen, len);
            }


            r++;
        }
        return maxlen;

    }
};

//  //brute force : generate all sub array 
// TC ~ O(N*N) | TLE ERROR
//         int n = nums.size();
//         int len =0 ;
//         int maxlen = 0;

//         for (int i = 0; i < n ; i ++){
//             int zero = 0;
//             for ( int j = i ; j < n ; j++){
//                 if(nums[j] == 0) {zero++;}
//                 if(zero <= k) {
//                      len = j-i+1;
//                      maxlen = max(maxlen, len);
//                 }
//                 else break;
//             }

//         }
//         return maxlen;