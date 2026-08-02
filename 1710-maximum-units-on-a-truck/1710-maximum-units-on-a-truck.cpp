class Solution {
public:

    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int ans = 0;

        for(int i = 0; i < boxTypes.size() && truckSize > 0; i++){

            int boxes = min(truckSize, boxTypes[i][0]);

            ans += boxes * boxTypes[i][1];

            truckSize -= boxes;
        }

        return ans;
    }
};