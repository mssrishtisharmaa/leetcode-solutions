class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {

        vector<int> nums;
        vector<char> ops;

        for(char c:s){
            if(isdigit(c))
                nums.push_back(c-'0');
            else
                ops.push_back(c);
        }

        int m=nums.size();

        // correct answer
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i=0;i<ops.size();i++){

            if(ops[i]=='*'){
                temp.back()*=nums[i+1];
            }
            else{
                temp.push_back(nums[i+1]);
            }
        }

        int correct=0;
        for(int x:temp)
            correct+=x;

        vector<vector<set<int>>> dp(m,vector<set<int>>(m));

        for(int i=0;i<m;i++)
            dp[i][i].insert(nums[i]);

        for(int len=2;len<=m;len++){

            for(int l=0;l+len-1<m;l++){

                int r=l+len-1;

                for(int k=l;k<r;k++){

                    for(int a:dp[l][k]){

                        for(int b:dp[k+1][r]){

                            int val;

                            if(ops[k]=='+')
                                val=a+b;
                            else
                                val=a*b;

                            if(val<=1000)
                                dp[l][r].insert(val);
                        }
                    }
                }
            }
        }

        int ans=0;

        for(int x:answers){

            if(x==correct)
                ans+=5;
            else if(dp[0][m-1].count(x))
                ans+=2;
        }

        return ans;
    }
};