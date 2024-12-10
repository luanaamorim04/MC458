#include <iostream> 
#define MAXN (int) (2e6)

using namespace std;

int n, m, val[MAXN], dp[MAXN];

int32_t main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> val[i];

	for (int i = 1; i < MAXN; i++) dp[i] = 1e9;

	for (int i = 1; i <= n; i++)
		for (int soma = val[i]; soma < MAXN; soma++)
			dp[soma] = min(dp[soma], 1 + dp[soma-val[i]]);

	for (int i = m; i < MAXN; i++)
		if (dp[i] != 1e9)
		{
			cout << i << ' ' << dp[i] << endl;
			return 0;
		}

	cout << -1 << endl;
}
