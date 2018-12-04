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
下面这种利用滑动窗口Sliding Window的方法也比较巧妙，首先统计字符串p的字符
个数，然后用两个变量left和right表示滑动窗口的左右边界，用变量cnt表示字符串
p中需要匹配的字符个数，然后开始循环，如果右边界的字符已经在哈希表中了，说
明该字符在p中有出现，则cnt自减1，然后哈希表中该字符个数自减1，右边界自加1，
如果此时cnt减为0了，说明p中的字符都匹配上了，那么将此时左边界加入结果res中。
如果此时right和left的差为p的长度，说明此时应该去掉最左边的一个字符，我们看
如果该字符在哈希表中的个数大于等于0，说明该字符是p中的字符，为啥呢，因为上
面我们有让每个字符自减1，如果不是p中的字符，那么在哈希表中个数应该为0，自减
1后就为-1，所以这样就知道该字符是否属于p，如果我们去掉了属于p的一个字符，cnt
自增1，参见代码如下：
*/

//下面这个解法的巧妙之处就在于：设置了一个cnt，并且窗口设置为可变的了
//cnt管理对上的情况:
//右边每对应上一个需要的字符，cnt--，
//当左边失去一个需要的字符，cnt++;

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
