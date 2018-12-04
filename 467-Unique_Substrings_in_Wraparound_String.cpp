/*
由于封装字符串是26个字符按顺序无限循环组成的，那么满足题意的p的子字符串要么
是单一的字符，要么是按字母顺序的子字符串。这道题遍历p的所有子字符串会TLE，
因为如果p很大的话，子字符串很多，会有大量的满足题意的重复子字符串，必须要用
到trick，而所谓技巧就是一般来说你想不到的方法。我们看abcd这个字符串，以d结
尾的子字符串有abcd, bcd, cd, d，那么我们可以发现bcd或者cd这些以d结尾的字符
串的子字符串都包含在abcd中，那么我们知道以某个字符结束的最大字符串包含其他
以该字符结束的字符串的所有子字符串，说起来很拗口，但是理解了我上面举的例子
就行。那么题目就可以转换为分别求出以每个字符(a-z)为结束字符的最长连续字符串
就行了，我们用一个数组cnt记录下来，最后在求出数组cnt的所有数字之和就是我们
要的结果啦
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26, 0);
        int len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
                ++len;
            } else {
                len = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], len);
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
