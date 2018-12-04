class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> target(h, vector<int>(w));
        vector<int> view_tb(w, -1);
        vector<int> view_lr(h, -1);

        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                view_tb[i] = max(view_tb[i], grid[j][i]);
            }
        }

        for(int j = 0; j < h; j++){
            for(int i = 0; i < w; i++){
                view_lr[j] = max(view_lr[j], grid[j][i]);
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                target[i][j] = min(view_tb[j], view_lr[i]);
            }
        }

        int ans = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                ans = ans - grid[i][j] + target[i][j];
            }
        }
        return ans;
    }
};
