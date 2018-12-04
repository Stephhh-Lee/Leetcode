//神奇的set的特性：

//所有元素都会根据元素的键值自动排序，set的元素不像map那样可以同时拥有实值
//(value)和键值(key),set元素的键值就是实值，实值就是键值。set不允许两个元素
//有相同的键值。

//从小到大排列


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int num : nums){
            s.insert(num);
            if(s.size() > 3){
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};
