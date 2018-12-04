//直接暴力搜索会超时；
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        int n = A.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    for(int l=0; l<n; l++) {
                        int sum = A[i] + B[j] + C[k] + D[l];
                        if(sum==0) {
                            cnt++;
                        }
                        else if(sum<0) continue;
                        else break;
                    }
                }
            }
        }
        return cnt;
    }
};

//循环一：建立两个map，一个是AB两数组元素和与出现次数的map，另一个为CD两数组元素和与出现次数的map，
//循环二：遍历map1，map2使用find函数来查找是否存在遍历元素的相反数。
//时间复杂度：706ms
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m1, m2;
        int result = 0;
        int n = A.size();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                  ++m1[A[i] + B[j]];
                  ++m2[C[i] + D[j]];
              }
        }
    /*    for(auto it = m1.begin(); it != m1.end(); ++it) {
            if(m2.find(-it->first) != m2.end())
                result += it->second * m2[-it->first];
        }  */
        for (auto p : m1) result += p.second * m2[-p.first];
        return result;
    }
};

/*
只使用一个map，建立AB两数组元素和与出现次数的map后，对CD遍历元素求和得opp，
result += m[-opp]，若-opp不存在，则m[-opp]为0，若存在，则result加上其出现的
次数。
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < B.size(); j++)
                m[A[i]+B[j]]++;
        for(int i = 0; i < C.size(); i++)
            for(int j = 0; j < D.size(); j++)
                ans += m[-(C[i]+D[j])];
        return ans;
    }
};

