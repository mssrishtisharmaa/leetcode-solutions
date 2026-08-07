class Solution {
    private: 
    int bfs(int row , int col , vector<vector<int>>& grid){
        int area = 1 ;
        queue<pair<int,int>> q;
        q.push({row , col});
        grid[row][col] = 0;
         int n = grid.size();
        int m = grid[0].size();
        int dr[]= { 1, -1 , 0 , 0 };
        int dc[]= {0,0,1,-1};

        while ( !q.empty()){
         int r =    q.front().first;
         int c = q.front().second;
         q.pop();

         // traverse neigbours 

         for ( int k = 0 ;  k < 4 ; k ++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                area ++;
                q.push({nr,nc});
                grid[nr][nc]=0;
            }
         }
        }


        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int area = 0;
        int n = grid.size();
        int m = grid[0].size();

        for ( int i = 0 ; i < n ; i ++){
            for ( int j = 0 ; j < m ; j ++){
                if(grid[i][j] == 1){
                    area = max(area , bfs(i , j , grid));
                }
            }
        }
        return area;
        
    }
};


