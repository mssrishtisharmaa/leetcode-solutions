class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       
        double sum = 0;
        int l = 0;
        int r = k-1;
        // windwo avg
        for(int i = l ; i <= r; i ++){
            sum = sum + nums[i];
        }
        double ans = sum;

        //slide the window
        while ( r < nums.size()-1){
            sum = sum - nums[l];
            l++;
            r++;
            sum = sum + nums[r];
           ans = max(ans, sum);

        }
return ans / k;
    }
};