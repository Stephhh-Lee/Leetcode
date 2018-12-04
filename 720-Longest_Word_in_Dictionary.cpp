/*
������������һ���ֵ䣬�Ǹ��ַ������飬Ȼ�������Ǵӵ����ַ���ʼƴ�����
���ɶ���ʣ�ע���м����ɵ��ַ���ҲҪ���ֵ��д��ڣ����ҵ���ɵĵ��ʳ������
ʱ��������ĸ˳��С���Ǹ����ã�������ô��ǰ׺һ�����ַ������ǲ��Ǻ������뵽
��ǰ׺����������ʵ���ǲ�����Ҫ�����Ľ���ǰ׺����㣬���Խ�����ҵ�˼��������
��ôΪ�˿��ٵĲ���ĳ�������Ƿ����ֵ��д��ڣ����ǽ����е��ʷŵ���ϣ�����У�
�ڲ��ҵ�ʱ�򣬿��Բ���BFS����DFS���С�������BFS��������ʹ��һ��queue��������
�����Ȱ����г���Ϊ1�ĵ����ҳ�����queue�У���������ѡ�֣�Ȼ�����ǽ���ѭ����
ÿ�δӶ���ȡһ��Ԫ�س���������䳤�ȴ�������ά�������ֵmxLen�������mxLen
�ͽ��res�����������ȣ�ҲҪ���½��res��ȡ��ĸ˳��С���Ǹ���Ȼ����������
���ӳ��ȣ��������Ǳ���26����ĸ����ÿ����ĸ���ӵ����ʺ��棬Ȼ���Ƿ����ֵ�
�д��ڣ����ڵĻ����ͼ���queue�еȴ���һ�α����������Ժ�ǵ�Ҫ�ָ�״̬���μ�
��������
*/

//unordered_set<> �ĳ�ʼ���� count����


class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        int mxLen = 0;
        unordered_set<string> s(words.begin(), words.end());
        queue<string> q;
        for (string word : words) {
            if (word.size() == 1) q.push(word);
        }
        while (!q.empty()) {
            string t = q.front(); q.pop();
            if (t.size() > mxLen) {
                mxLen = t.size();
                res = t;
            } else if (t.size() == mxLen) {
                res = min(res, t);
            }
            for (char c = 'a'; c <= 'z'; ++c) {
                t.push_back(c);
                if (s.count(t)) q.push(t);
                t.pop_back();
            }
        }
        return res;
    }
};


/*
���������ݹ�Ľⷨ��ǰ�涼һ������ͬ����ֱ�ӶԳ���Ϊ1�ĵ��ʵ��õݹ麯����
�ڵݹ��У��������жϵ��ʺ�mxLen��ϵ�����½��res��Ȼ����Ǳ��������ַ���
�ӵ����ʺ��棬����ڼ����д��ڣ����õݹ麯����������ָ�״̬���μ��������£�
*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        int mxLen = 0;
        unordered_set<string> s(words.begin(), words.end());for (string word : words) {
            if (word.size() == 1) helper(s, word, mxLen, res);
        }
        return res;
    }
    void helper(unordered_set<string>& s, string word, int& mxLen, string& res) {
        if (word.size() > mxLen) {
            mxLen = word.size();
            res = word;
        } else if (word.size() == mxLen) {
            res = min(res, word);
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            word.push_back(c);
            if (s.count(word)) helper(s, word, mxLen, res);
            word.pop_back();
        }
    }
};

/*
�������ֽⷨ����̳�ϵĸ߷ֽⷨ����ʵ����ֻҪ�������Ÿ��򣬾Ϳ���ʹ��̰
���㷨�����ˣ�������ҪʲôDFS��BFS��ô���ӡ����Ƚ���һ���յĹ�ϣset��Ȼ
������ֱ�ӱ����������ֵ䣬���ڵ�ǰ�ĵ��ʣ������ǰ���ʳ���Ϊ1�����߸�
����ȥ�����һ����ĸ���ڼ����д��ڣ���Ҳ������⣬����Ϊ1��˵������ʼ��
�ʣ�����Ҫ�Ķ�����жϣ�����Ļ���Ҫ�ж���ȥ�����һ����ĸ��ĵ����Ƿ���
�����д��ڣ����ڵĻ�����˵�����м䵥�ʶ����ڣ���Ϊ��ʱ�ǴӶ̵����򳤵���
������ֻҪ����Ҫ��ĲŻ���뼯�ϣ�����һ����ȥ��β��ĸ�ĵ��ʴ��ڵĻ�����
ô��֮ǰ���е��м���������ڼ����д��ڡ����Ǹ��½��resʱ��Ҫ�жϵ�ǰ��
�ʳ����Ƿ���ڽ��res�ĳ��ȣ���Ϊ�������Ĭ���ȸ��µ���ĸ˳��С�ĵ��ʣ�
����ֻ�е���ǰ���ʳ��ȴ󣬲Ÿ��½��res��֮������˰ѵ�ǰ���ʼ��뼯���У�
�μ��������£�
*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_set<string> s;
        sort(words.begin(), words.end());
        for (string word : words) {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1))) {
                res = (word.size() > res.size()) ? word : res;
                s.insert(word);
            }
        }
        return res;
    }
};
