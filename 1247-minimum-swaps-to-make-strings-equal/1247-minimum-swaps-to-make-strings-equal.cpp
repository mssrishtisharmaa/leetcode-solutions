class Solution {
public:
    int minimumSwap(string s1, string s2) {

        int cntXY = 0;
        int cntYX = 0;

        for (int i = 0; i < s1.size(); i++) {

            if (s1[i] == 'x' && s2[i] == 'y')
                cntXY++;

            else if (s1[i] == 'y' && s2[i] == 'x')
                cntYX++;
        }

        if ((cntXY + cntYX) % 2)
            return -1;

        return cntXY / 2 + cntYX / 2 + 2 * (cntXY % 2);
    }
};