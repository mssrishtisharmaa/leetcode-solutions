class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
        
    }
private: 
  int atmost(vector<int>& nums, int goal){
    if (goal < 0) return 0;
    int l = 0;
    int r = 0;
    int sum = 0;
    int cnt = 0;

    while ( r < nums.size()){
        sum += nums[r];
        

        while(sum> goal){
            sum -= nums[l];
            l++;
        }
        cnt += (r - l +1);
        r++;
    }
    return cnt;

  }
};



// // same sol as PROBLEM : 560 [ it was used in array for + , - and  zero]

// same solution will work but ( not most optimal one )

// there fore we need to optimize it 

// sol :
// map<int , int> mpp;
//        mpp[0] = 1;
//        int prefix_sum = 0;
//        int cnt = 0;
//        for(int i = 0; i < nums.size() ; i++){
//         prefix_sum += nums[i];
//         int remove = prefix_sum - goal;
//         cnt += mpp[remove];
//         mpp[prefix_sum] += 1;
//        }
//        return cnt;

