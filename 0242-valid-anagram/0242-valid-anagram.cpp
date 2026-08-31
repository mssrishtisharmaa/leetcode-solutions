class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int, int> mp;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        // check
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]--;
        }
        bool allzero = true;
        for (auto& p : mp) {
            if (p.second != 0) {
                allzero = false;
                break;
            }
        }
        if (allzero)
            return true;
        else
            return false;
    }
};