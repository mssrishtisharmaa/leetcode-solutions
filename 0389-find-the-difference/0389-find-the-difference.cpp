class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        int l = 0 ; 
       int  r = 0 ;
        while ( r < s.size() && l < t.size()){
            if(s[r] != t[l]) break;

            r++;
            l++;

        }
        return t[l];
    }
};