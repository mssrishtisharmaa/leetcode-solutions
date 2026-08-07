class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int check = image[sr][sc];
        if (check == color)return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        int n = image.size();
        int m = image[0].size();
        while ( !q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for ( int k = 0 ; k < 4 ; k ++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == check){
                    q.push({nr,nc});
                    image[nr][nc] = color;
                    
                }
            }
           


        }
         return image;

    }
};