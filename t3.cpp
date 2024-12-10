#include <iostream> 
#include <string.h>
#include <algorithm>
#include <vector> 
#define MAXN (int) 105
#define ii pair<int, int> 

using namespace std;

string s[MAXN];
int t, n, m;

int32_t main()
{
	cin >> t;
	while (t--)
	{
		vector<ii> v;
		cin >> m >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			int freq[300], inv = 0;
			memset(freq, 0, sizeof freq);
			for (int j = m-1; j >= 0; j--)
			{
				freq[s[i][j]]++;
				for (int k = 0; k < s[i][j]; k++)
					inv += freq[k];
			}

			v.push_back({inv, i});
		}

		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
			cout << s[v[i].second] << endl;
		if (t) cout << endl;
	}
}
