class Solution {
public:
    bool isMagic(int h, int w, vector<vector<int>>& grid){
        for(int i = h; i < h+3; i++){
            for(int j = w; j < w+3; j++){
                if(grid[i][j]>9 || grid[i][j]<1) return false;
            }
        }
        for(int i = h; i < h+3; i++){
            if(grid[i][w] == grid[i][w+1] || grid[i][w] == grid[i][w+2] || grid[i][w+1] == grid[i][w+2]) return false;
        }
        for(int j = w; j < w+3; j++){
            if(grid[h][j] == grid[h+1][j] || grid[h][j] == grid[h+2][j] || grid[h+1][j] == grid[h+2][j]) return false;
        }
        int sum = grid[h][w]+grid[h+1][w+1]+grid[h+2][w+2];
        if(grid[h+2][w]+grid[h+1][w+1]+grid[h][w+2] != sum) return false;
        for(int i = h; i < h+3; i++){
            if(grid[i][w]+grid[i][w+1]+grid[i][w+2] != sum) return false;
        }
        for(int j = w; j < w+3; j++){
            if(grid[h][j]+grid[h+1][j]+grid[h+2][j] != sum) return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int height = grid.size(), width = grid[0].size();
        if(height < 3 && width < 3) return 0;
        int ans = 0;
        for(int i = 0; i <= height-3; i++){
            for(int j = 0; j <= width-3; j++){
                if(isMagic(i, j, grid)) ans++;
            }
        }
        return ans;
    }
};