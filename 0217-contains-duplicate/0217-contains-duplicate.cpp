class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    set<int> s;
     for (size_t i = 0; i < n; ++i) {
         s.insert(nums[i]);
    }
      if (s.size() != n) {
        return true;
    }else {return false;}
        
    }
};