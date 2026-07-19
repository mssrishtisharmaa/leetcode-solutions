class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while (true) {

            vector<vector<int>> visited(m, vector<int>(n, 0));

            vector<vector<pair<int,int>>> regions;
            vector<set<pair<int,int>>> frontiers;
            vector<int> walls;

            // Find all regions
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {

                    if (grid[i][j] != 1 || visited[i][j])
                        continue;

                    regions.push_back({});
                    frontiers.push_back({});
                    walls.push_back(0);

                    int idx = regions.size() - 1;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();

                        regions[idx].push_back({x,y});

                        for (auto [dx,dy] : dir) {
                            int nx = x + dx;
                            int ny = y + dy;

                            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                                continue;

                            if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                                visited[nx][ny] = 1;
                                q.push({nx,ny});
                            }
                            else if (grid[nx][ny] == 0) {
                                walls[idx]++;
                                frontiers[idx].insert({nx,ny});
                            }
                        }
                    }
                }
            }

            if (regions.empty())
                break;

            // Find region with largest frontier
            int best = -1;
            int mx = 0;

            for (int i = 0; i < frontiers.size(); i++) {
                if ((int)frontiers[i].size() > mx) {
                    mx = frontiers[i].size();
                    best = i;
                }
            }

            if (mx == 0)
                break;

            ans += walls[best];

            // Quarantine chosen region
            for (auto [x,y] : regions[best])
                grid[x][y] = -1;

            // Spread remaining regions
            for (int i = 0; i < regions.size(); i++) {

                if (i == best)
                    continue;

                for (auto cell : frontiers[i]) {
                    grid[cell.first][cell.second] = 1;
                }
            }
        }

        return ans;
    }
};