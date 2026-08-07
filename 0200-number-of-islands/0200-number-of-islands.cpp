class Solution {
    private: 
void bfs( int row , int col ,vector<vector<char>>& grid ){
    queue<pair<int , int>> q;
     int dr[] = {1 , -1, 0 ,0};
    int dc[] = {0, 0, -1 , 1};
       int n = grid.size();
        int m = grid[0].size(); 
    q.push({row , col});
    grid[row][col] = 0;

    while ( !q.empty()){
   int r = q.front().first;
int c = q.front().second;
    q.pop()  ;   

    //neigbouts 
    for ( int k = 0 ; k < 4; k ++){
        int nr = r + dr[k];
        int nc = c + dc[k];

        if( nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1'){
            q.push({nr, nc});
            grid[nr][nc] = '0';
        }
    }
    
    }

}
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0 ;

        for ( int i = 0 ; i < n ; i ++){
            for ( int j = 0 ; j < m ; j++){
                if (grid[i][j] == '1'){
                    cnt++;
                    bfs( i , j , grid);
                    
                }
            }
        }
        return cnt;
        
    }
};
