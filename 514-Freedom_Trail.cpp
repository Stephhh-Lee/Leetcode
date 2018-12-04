//超时了

/*
思路：回溯
将key倒序搜索，
用一个int记录当前位置
每一次搜索都取最近的那个字符
记录最终那一个字符的位置，若有m个最终字符，就从m个字符分别开始
最终回到0

这种题，开头是一定的，结束位置有多种可能
若倒序，则开启位置有有限个可能，结束位置只有一种可能，
并且可以用贪心，大大减少了需要考虑的情况。
*/

class Solution
{
public:
    int findForward(string s, char c)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == c)
                return i;
        }
    }
    //int findBackward(string s, char c){
    //    for(int i = s.size() - 1; i > -1; i--){
    //        if(s[i] == c) return (i+1)%s.size();
    //    }
    //}
    int findBackward(string s, char c)
    {
        if(s[0] == c)
            return 0;
        else
        {
            for(int i = s.size() - 1; i > 0; i--)
            {
                if(s[i] == c)
                    return i;
            }
        }
    }
    void findSteps(string ring, string key, int step, int& ans)
    {
        int m, n;
        int len = ring.size();
        if(key.size() == 0)
        {
            ans = min(step, ans);
            return;
        }
        m = findForward(ring, key[0]);
        //n = findBackward(ring.substr(1, ring.size()) + ring.substr(0, 1), key[0]);
        n = findBackward(ring, key[0]);
        if(m == len - n)
        {
            step += min(m, len - m) + 1;
            findSteps(ring.substr(m, len) + ring.substr(0, m), key.substr(1,key.size()), step, ans);
        }
        else
        {
            findSteps(ring.substr(m, len) + ring.substr(0, m), key.substr(1,key.size()), step + m + 1, ans);
            findSteps(ring.substr(n, len) + ring.substr(0, n), key.substr(1,key.size()), step + len - n + 1, ans);
        }
    }

    int findRotateSteps(string ring, string key)
    {
        int step = 0;
        int ans = INT_MAX;
        findSteps(ring, key, step, ans);
        return ans;
    }
};


class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int rlen = ring.size(), klen = key.size();
        if(rlen == 0 || klen == 0)
            return 0;

        //记录每个字符在ring中的位置，一个字符可能对应多个位置
        vector<vector<int> >mp(26, vector<int>());
        for(int i = 0; i < rlen; ++i)
        {
            mp[ring[i]-'a'].push_back(i);
        }

        vector<int> prev(1, 0);   //保存
        vector<int> best(rlen, INT_MAX);
        best[0] = 0;
        for(int i = 0; i < klen; ++i)
        {
            vector<int> tmp_best(rlen, INT_MAX);
            vector<int> next;
            for(auto p:prev)
            {
                for(auto c:mp[key[i]-'a'])
                {
                    int cost = min((c-p+rlen)%rlen, (p-c+rlen)%rlen) + best[p];
                    tmp_best[c] = min(tmp_best[c], cost);
                }
            }
            best = tmp_best;
            prev = mp[key[i]-'a'];
        }

        int res = INT_MAX;
        for(auto b:best)
        {
            res = min(res, b);
        }
        return res + klen;
    }
};

