class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int width = A[0].size();
        int height = A.size();
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width/2; j++){
                int tmp = A[i][j];
                A[i][j] = A[i][width - 1 - j];
                A[i][width - 1 - j] = tmp;
            }
        }
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;
    }
};
