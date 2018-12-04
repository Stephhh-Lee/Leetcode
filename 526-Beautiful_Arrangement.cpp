class Solution {
public:
    int countArrangement(int N) {
        int ans = 0;
        vector<int> v(N+1, 0);
        helper(N, v, 1, ans);
        return ans;
    }
    void helper(int n, vector<int>& v, int pos, int& ans){
        if(pos > n){
            ans++;
            return;
        }
        for(int i=1; i<=n; i++){
            if(v[i]==0 &&(i%pos==0 || pos%i==0)){
                v[i]=1;
                helper(n,v,pos+1,ans);
                v[i]=0;
            }
        }
    }
};





class Solution {
public:
    typedef struct {
        int   cnt;
        char* dat;
    } entryType;

    int dfs(entryType* entries, bool* visit, int n, int N, int cnt) {
        if (n > N) return ++cnt;

        int c = entries[n].cnt;
        for (int i = 1; i <= c; ++i) {
            bool* v = visit + entries[n].dat[i];

            // Skip for duplicated digits
            if (*v) continue;

            *v = true;
            cnt = dfs(entries, visit, n + 1, N, cnt);
            *v = false;
        }

        return cnt;
    }

    int countArrangement(int N) {
        // Example
        //         1 2 3 4 5
        // entry 1 1 2 3 4 5 cnt = 5
        // entry 2 1 2 0 4 0 cnt = 3
        // entry 3 1 0 3 0 0 cnt = 2
        // entry 4 1 2 0 4 0 cnt = 3
        // entry 5 1 0 0 0 5 cnt = 2

        char      buf[N + 1][N + 1] = {};
        entryType entries[N + 1]    = {};
        bool      visit[N + 1]      = {};

        for (int i = 1; i <= N; ++i) {
            entries[i].dat = buf[i];
        }

        // Construct candiates
        for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; j += i) {
                entries[i].dat[j] = j;
                entries[j].dat[i] = i;
            }
        }

        // Pack data
        for (int i = 1; i <= N; ++i) {
            char* d = entries[i].dat;
            int   j = 1;
            int   k = N;

            while (j <= k) {
                while (j <= N && d[j] != 0) ++j;
                while (k >  0 && d[k] == 0) --k;

                if (j < k) {
                    char t = d[j];
                    d[j] = d[k];
                    d[k] = t;
                }
            }

            entries[i].cnt = j - 1;
        }

        // Sort for performance
        sort(entries + 1, entries + N + 1,
             [](const entryType& a, const entryType& b) -> bool
             {
                 return a.cnt < b.cnt;
             });

        // DFS
        return dfs(entries, visit, 1, N, 0);
    }
};

