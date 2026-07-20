class Solution {
public:
    vector<string> ans;

    void dfs(string &num, long long target, int pos,
             long long eval, long long prev,
             string expr) {

        if (pos == num.size()) {
            if (eval == target)
                ans.push_back(expr);
            return;
        }

        long long cur = 0;

        for (int i = pos; i < num.size(); i++) {

            if (i > pos && num[pos] == '0')
                break;

            cur = cur * 10 + (num[i] - '0');

            string part = num.substr(pos, i - pos + 1);

            if (pos == 0) {

                dfs(num, target,
                    i + 1,
                    cur,
                    cur,
                    part);

            } else {

                dfs(num, target,
                    i + 1,
                    eval + cur,
                    cur,
                    expr + "+" + part);

                dfs(num, target,
                    i + 1,
                    eval - cur,
                    -cur,
                    expr + "-" + part);

                dfs(num, target,
                    i + 1,
                    eval - prev + prev * cur,
                    prev * cur,
                    expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        dfs(num, target, 0, 0, 0, "");

        return ans;
    }
};