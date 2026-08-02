class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int l = 0; // cookies
        int r = 0; // child
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while ( l < n && r < m){
            if(g[r] <= s[l]){
                r++;
            }
            l++;

        }
        return r;
        
    }
};