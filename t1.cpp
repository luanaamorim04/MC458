#include <iostream>
#define MAXN (int) (1e6 + 10)

using namespace std;

int x, q, n, arr[MAXN], pos;
char op;

int32_t main()
{
	cin >> n >> q;
	pos = 1;
	while (q--)
	{
		cin >> op;
		if (op == 'i' && cin >> x) arr[x] = pos;
		else if (op == 'r' && cin >> x) arr[x] = 0;
		else if (op == 'l') pos++;
		else if (cin >> x) cout << (arr[x] == pos ? 1 : 0) << endl;
	}
}
