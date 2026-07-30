class Solution {
public:
    int countGoodSubstrings(string s) {

   vector<int> freq(26,0);

    int l = 0 ;
    int r = 0;
    int count = 0;
    int disint = 0;
        //base case 
        while(r < s.size()){
            freq[s[r] - 'a']++;
            if( freq[s[r] - 'a'] == 1 ) disint ++;

            if( (r-l+1) > 3 ){
                freq[s[l] - 'a']--;
                if( freq[s[l] - 'a'] == 0) disint --;
                l++;
            }
            if((r-l+1) == 3 && disint ==3 ){
                count++;
            }

            r++;
        }
        return count;

        // invalid ( shrink 
        
        //valid count and explan)
        
    }
};