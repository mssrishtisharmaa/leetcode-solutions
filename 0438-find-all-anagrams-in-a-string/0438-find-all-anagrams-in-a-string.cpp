class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int r = 0;
        int l = 0;
        map<int, int> mp ;

        // store indices of p
        for (int i = 0; i < p.size(); i++) {
            mp[p[i]]++;
        }
      
        while ( r < p.size()-1){
             mp[s[r]]--;
             r++;

        }

        while (r < s.size()) {
            // base
            mp[s[r]]--;

            // invlaid
            bool allZero = true;

            for (auto& p : mp) {
                if (p.second != 0) {
                    allZero = false;
                    break;
                }
            }

            if (allZero) {
                ans.push_back(l);

                
            }
            
                mp[s[l]]++;
                l++;
            

            // vlaid
            r++;

          
        }

        return ans;
    }
};