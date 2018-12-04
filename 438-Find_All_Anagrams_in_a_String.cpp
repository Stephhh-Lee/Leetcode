class Solution {
public:
    bool allZero(vector<int>& cnt){
        for(auto x:cnt){
            if(x != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size()>=p.size()){
            vector<int> cnt(128, 0);
            for(int i = 0; i < p.size(); i++) {
                --cnt[p[i]];
                ++cnt[s[i]];
            }
            if(allZero(cnt)) ans.push_back(0);
            for(int i = p.size(); i < s.size(); i++){
                ++cnt[s[i]];
                --cnt[s[i-p.size()]];
                if(allZero(cnt)) ans.push_back(i-p.size()+1);
            }

        }
        return ans;
    }
};


/*
�����������û�������Sliding Window�ķ���Ҳ�Ƚ��������ͳ���ַ���p���ַ�
������Ȼ������������left��right��ʾ�������ڵ����ұ߽磬�ñ���cnt��ʾ�ַ���
p����Ҫƥ����ַ�������Ȼ��ʼѭ��������ұ߽���ַ��Ѿ��ڹ�ϣ�����ˣ�˵
�����ַ���p���г��֣���cnt�Լ�1��Ȼ���ϣ���и��ַ������Լ�1���ұ߽��Լ�1��
�����ʱcnt��Ϊ0�ˣ�˵��p�е��ַ���ƥ�����ˣ���ô����ʱ��߽������res�С�
�����ʱright��left�Ĳ�Ϊp�ĳ��ȣ�˵����ʱӦ��ȥ������ߵ�һ���ַ������ǿ�
������ַ��ڹ�ϣ���еĸ������ڵ���0��˵�����ַ���p�е��ַ���Ϊɶ�أ���Ϊ��
����������ÿ���ַ��Լ�1���������p�е��ַ�����ô�ڹ�ϣ���и���Ӧ��Ϊ0���Լ�
1���Ϊ-1������������֪�����ַ��Ƿ�����p���������ȥ��������p��һ���ַ���cnt
����1���μ��������£�
*/

//��������ⷨ������֮�������ڣ�������һ��cnt�����Ҵ�������Ϊ�ɱ����
//cnt������ϵ����:
//�ұ�ÿ��Ӧ��һ����Ҫ���ַ���cnt--��
//�����ʧȥһ����Ҫ���ַ���cnt++;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for (char c : p) ++m[c];
        while (right < n) {
            if (m[s[right++]]-- >= 1) --cnt;
            if (cnt == 0) res.push_back(left);
            if (right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;
        }
        return res;
    }
};
