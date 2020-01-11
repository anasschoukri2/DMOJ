#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define INF 100000000
#define MOD 1000000007
using namespace std;
int n, t;
typedef pair<long long int, long long int> ii;
typedef vector<ii> u;
vector<u> v;
long long int dp[3][100020];
int main()
{
    ms(dp, 0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        vector<ii> p;
        for (int j = 0; j < 3; j++) {
            ii a;
            cin >> a.first >> a.second;
            p.push_back(a);
        }
        v.push_back(p);
    }
    for (int i = 0; i <= t; i++) {
        long long int ans = 0;
        for (int k = 0; k < 3; k++) {
            if (i - v[0][k].first >= 0)
                ans = max(ans, v[0][k].second);
        }
        dp[0][i] = ans;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= t; j++) {
            long long int ans = 0;
            for (int k = 0; k < 3; k++) {
                if (j - v[i][k].first >= 0)
                    ans = max(ans, dp[0][j - v[i][k].first] + v[i][k].second);
            }
            dp[1][j] = max(dp[0][j], ans);
        }
        for (int j = 0; j <= t; j++)
            dp[0][j] = dp[1][j];
    }
    long long int ans = 0;
    for (int j = 0; j <= t; j++)
        ans = max(ans, dp[0][j]);
    cout << ans;
    return 0;
}
