class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        vector<pair<int, int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {

                    islands++;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';

                    while (!q.empty()) {

                        auto [x,y] = q.front();
                        q.pop();

                        for (auto [dx,dy] : dir) {

                            int nx = x + dx;
                            int ny = y + dy;

                            if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                                grid[nx][ny] == '1') {

                                grid[nx][ny] = '0';
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};