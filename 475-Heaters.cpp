//将house作为标定点，找每一个house都在heater的范围内的最小距离。
//这样只需要考虑每一个house的左边一个heater和右边一个heater。

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(house.begin(), house.end());
        sort(heater.begin(), heater.end());
        int result = 0;
        int temp = 0;
        int j = 0;
        for (int i = 0; i < houses.length; i++) {
        	while (j < heaters.length && heaters[j] < houses[i])
        		j++;
        	if (j == heaters.length)
        		temp = houses[i] - heaters[j - 1];
        	else if (j == 0)
        		temp = heaters[j] - houses[i];
        	else if (heaters[j] > houses[i])
        		temp = min(heaters[j] - houses[i], houses[i] - heaters[j - 1]);
        	if (temp > result)
        		result = temp;
       	}
        return result;
    }
};
