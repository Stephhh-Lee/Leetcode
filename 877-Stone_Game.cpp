/*
�ⷨ1�� ֱ�ӷ���true[Accepted]
�����Ŀ��Ȥ�ĵط����ڣ�ͨ����������������������ֱ���ж�˭��ʤ����
Alex�ǵ�һ��ȥѡ����ˣ�����piles.length��ż������͵����ˣ�Alex��������ѡ�±�Ϊż����piles�����±�Ϊ������piles��
�ٸ����ӣ�piles.length=n��Ϊż����
���Alex��ȥѡ���±�Ϊż����piles������һ�ֿ���ѡ��piles[0].֮��Leeֻ�ܴ�piles[1]~piles[n-1]������ѡ�񣬶���������ѡ�񶼿���ʹ��Alex��һ��
����ѡ���±�Ϊż����piles������ѭ��������Alex���Խ������±�Ϊż����pilesѡ�ߣ���Leeֻ��ѡ���±�Ϊ������piles����֮��Ȼ��
ͬʱ��Ŀ��������һ������������sum(piles)�����������sum(piles[even]) > sum(piles[odds])��ôAlexѡ��ż����piles����ȡ��ʤ������֮ѡ��������
piles����ȡ��ʤ����
���ϣ�Alex���ǿ���Ӯ��ֱ��return true����AC��

*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

/*
�ⷨ2�� DP
�ⷨ1��Ҫ�ܶ�����������ſ��Գ����������������Ⲣ�������߱������ͼ������һ�������������Ŀ����ͨ����̬�滮��⡣����һ�������ָ�����
piles.lengthΪ��������ô�죿������������ȷ��֪�������Ĳ���ָ���δ���

���ڶ�̬�滮���⣬һ����ʲô����ʲô��������������dp[i][j]��ʾ��piles[i]��piles[j]����Աȶ��ֶ�õ����ķ������������ǵ�����Ŀ����dp[0][n-1]��
����������Ҫȷ��ת�Ʒ��̺ͳ�ʼ������
��piles[i]~piles[j]�У������ѡ��piles[i]����piles[j]��
�����ѡ����piles[i]����ô��Ķ��־ͻ��piles[i+1]~piles[j]�еõ����ķ�����������ֵΪpiles[i]-dp[i+1][j].(��ĿҪ�󶼷������ˮƽ�����Զ��ڶ�
�ֶ���dp�ĺ���һ����,�����ʣ�µ�piles��ѡ�����ķ�����������������������
�����ѡ����piles[j],������ֵΪpiles[j] - dp[i][j-1].

����״̬ת�Ʒ���Ϊ��
dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])

��ʼ����Ϊ��
�� i == j ʱ�� dp[i][i] = piles[i]
*/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) dp[i][i] = piles[i];
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                dp[i][i+len-1] = max(piles[i] - dp[i+1][i+len-1], piles[i+len-1] - dp[i][i+len-2]);
            }
        }
        return dp[0][n-1]>0;
    }
};
