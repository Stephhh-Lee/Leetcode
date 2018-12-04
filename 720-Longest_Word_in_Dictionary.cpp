/*
这道题给了我们一个字典，是个字符串数组，然后问我们从单个字符开始拼，最长能
组成啥单词，注意中间生成的字符串也要在字典中存在，而且当组成的单词长度相等
时，返回字母顺序小的那个。好，看到这么多前缀一样多字符串，是不是很容易想到
用前缀树来做，其实我们并不需要真正的建立前缀树结点，可以借鉴查找的思想来做。
那么为了快速的查找某个单词是否在字典中存在，我们将所有单词放到哈希集合中，
在查找的时候，可以采用BFS或者DFS都行。先来看BFS的做法，使用一个queue来辅助，
我们先把所有长度为1的单词找出排入queue中，当作种子选手，然后我们进行循环，
每次从队首取一个元素出来，如果其长度大于我们维护的最大值mxLen，则更新mxLen
和结果res，如果正好相等，也要更新结果res，取字母顺序小的那个。然后我们试着
增加长度，做法就是遍历26个字母，将每个字母都加到单词后面，然后看是否在字典
中存在，存在的话，就加入queue中等待下一次遍历，完了以后记得要恢复状态，参见
代码如下
*/

//unordered_set<> 的初始化和 count函数


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
下面来看递归的解法，前面都一样，不同在于直接对长度为1的单词调用递归函数，
在递归中，还是先判断单词和mxLen关系来更新结果res，然后就是遍历所有字符，
加到单词后面，如果在集合中存在，调用递归函数，结束后恢复状态，参见代码如下：
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
下面这种解法是论坛上的高分解法，其实我们只要给数组排个序，就可以使用贪
婪算法来做了，并不需要什么DFS或BFS这么复杂。首先建立一个空的哈希set，然
后我们直接遍历排序后的字典，对于当前的单词，如果当前单词长度为1，或者该
单词去掉最后一个字母后在集合中存在，这也不难理解，长度为1，说明是起始单
词，不需要的多余的判断，否则的话就要判断其去掉最后一个字母后的单词是否在
集合中存在，存在的话，才说明其中间单词都存在，因为此时是从短单词向长单词
遍历，只要符合要求的才会加入集合，所以一旦其去掉尾字母的单词存在的话，那
么其之前所有的中间情况都会在集合中存在。我们更新结果res时，要判断当前单
词长度是否大于结果res的长度，因为排序过后，默认先更新的字母顺序小的单词，
所有只有当当前单词长度大，才更新结果res，之后别忘了把当前单词加入集合中，
参见代码如下：
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
