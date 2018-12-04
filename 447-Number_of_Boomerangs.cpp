#include<iostream>
#include<vector>
using namespace std;

int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int len = points.size(), res = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int x = points[i].first - points[j].first;
            int y = points[i].second - points[j].second;
            m[x * x + y * y]++;
        }

        unordered_map<int, int> :: iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            int tmp = it->second;
            res += tmp * (tmp - 1);
        }
        m.clear();
    }

    return res;
}
