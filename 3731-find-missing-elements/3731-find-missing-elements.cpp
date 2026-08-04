class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int min = nums[0];
       
        vector<int> ans;

        for ( int j = 0 ; j < n ; j ++ , min ++){
             while( min < nums[j]){
                ans.push_back(min);
                j--;
             }
         
            
        }
         return ans;
        }
       
       
       
        
    
};