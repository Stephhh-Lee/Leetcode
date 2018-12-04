class Solution {
public:
    void reverse_row(vector<vector<int>>& A, int i){
        for(int j = 0; j < A[i].size(); j++){
            A[i][j] = (A[i][j] + 1)%2;
        }
    }
    void reverse_column(vector<vector<int>>& A, int i){
        for(int j = 0; j < A.size(); j++){
            A[j][i] = (A[j][i] + 1)%2;
        }
    }
    bool get_column(vector<vector<int>>& A, int i){
        int sum = 0;
        for(int j = 0; j < A.size(); j++){
            sum += A[j][i];
        }
        if(A.size()%2 == 0)
            return sum >= A.size()/2;
        return sum > A.size()/2;
    }
    int b_to_int(vector<vector<int>>& A, int i){
        int ans = 0;
        //for(int j = 0; j < A[0].size(); j++){
        for(int j = 0; j < A[i].size(); j++){
            ans = ans*2 + A[i][j];
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& A) {

        for(int i = 0; i < A.size(); i++){
            if(A[i][0] == 0) reverse_row(A, i);
        }

        for(int i = 1; i < A[0].size(); i++){
            if(!get_column(A, i)) reverse_column(A, i);
        }

        int ans = 0;
        //vector<int> ans;
        for(int i = 0; i < A.size(); i++){
            ans += b_to_int(A, i);
            //ans.push_back(b_to_int(A, i));
        }
        return ans;
    }
};
