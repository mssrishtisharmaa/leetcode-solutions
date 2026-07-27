class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
       int largest = 0;
       int slargest = 0;
       int n = nums.size();
       for (int i = 0 ; i < n ; i ++){
        if(nums[i] > largest){
            slargest = largest;
            largest = nums[i];
            
        }
        else if ( nums[i] > slargest){
            slargest = nums[i];
        }
       }
        return (largest - 1) * (slargest -1);



       // find index of 2nd largest 

        
    }
};