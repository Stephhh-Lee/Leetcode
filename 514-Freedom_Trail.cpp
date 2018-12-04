//��ʱ��

/*
˼·������
��key����������
��һ��int��¼��ǰλ��
ÿһ��������ȡ������Ǹ��ַ�
��¼������һ���ַ���λ�ã�����m�������ַ����ʹ�m���ַ��ֱ�ʼ
���ջص�0

�����⣬��ͷ��һ���ģ�����λ���ж��ֿ���
����������λ�������޸����ܣ�����λ��ֻ��һ�ֿ��ܣ�
���ҿ�����̰�ģ�����������Ҫ���ǵ������
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

        //��¼ÿ���ַ���ring�е�λ�ã�һ���ַ����ܶ�Ӧ���λ��
        vector<vector<int> >mp(26, vector<int>());
        for(int i = 0; i < rlen; ++i)
        {
            mp[ring[i]-'a'].push_back(i);
        }

        vector<int> prev(1, 0);   //����
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

