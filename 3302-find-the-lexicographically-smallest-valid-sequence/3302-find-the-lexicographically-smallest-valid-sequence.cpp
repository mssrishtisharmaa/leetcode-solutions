class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m, -1);

        int j = m - 1;

        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                suf[j] = i;
                j--;
            }
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int i = 0; i < m; i++) {

            while (pos < n && word1[pos] != word2[i]) {

                if (!usedMismatch) {

                    if (i == m - 1 || 
                        (suf[i + 1] != -1 && suf[i + 1] > pos)) {

                        ans.push_back(pos);
                        usedMismatch = true;
                        pos++;
                        break;
                    }
                }

                pos++;
            }

            if (ans.size() == i) {

                if (pos >= n)
                    return {};

                ans.push_back(pos);
                pos++;
            }
        }

        return ans;
    }
};