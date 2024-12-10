#include <iostream> 
#define int long long
#define ii pair<int, int> 
#define MAXN (int) (1e6 + 10)

using namespace std;

int peso, nivel[MAXN], pai[MAXN], idx, esq[MAXN], dir[MAXN];
char c;

void f(int u, int p = 0)
{
	int peso;
	char c;
	cin >> peso >> c;
	nivel[u] = peso;
	if (c == 'T') esq[u] = ++idx, f(idx, u);
	cin >> c;
	if (c == 'T') dir[u] = ++idx, f(idx, u);
}

ii dfs(int u, int p = 0)
{
	int h1 = 0, h2 = 0, d1 = 0, d2 = 0;
	if (esq[u])
	{
		ii p = dfs(esq[u], u);
		h1 = max(0LL, p.first);
		d1 = p.second;
	}
	if (dir[u])
	{
		ii p = dfs(dir[u], u);
		h2 = max(0LL, p.first);
		d2 = p.second;
	}

	int h = max(h1, h2) + nivel[u];
	return {h, max(max(h, d1), max(d2, h1 + h2 + nivel[u]))};
}

int32_t main()
{
	f(++idx);
	cout << dfs(1).second << endl;
}
