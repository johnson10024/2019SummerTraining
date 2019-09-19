#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define INF (0x3f3f3f3f)
#define MOD (998244353)
#define PREC (0.0000001)
#define X first
#define Y second
// #define DEBUG

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

void init()
{
}

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);

	map<int, int> mp;
	vector<int> vec;
	int temp;
	int cur = 1;

	while(n + m > 0)
	{
		mp.clear();
		vec.clear();

		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &temp);
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());

		for(int i = 1; i <= n; i++)
		{
			mp.insert({vec[i - 1], i});
		}

		printf("CASE# %d:\n", cur);
		for(int i = 0; i <= m - 1; i++)
		{
			scanf("%d", &temp);
			if(mp.find(temp) != mp.end())
			{
				printf("%d found at %d\n", temp, mp[temp]);
			}
			else
			{
				printf("%d not found\n", temp);
			}
		}

		scanf("%d %d", &n, &m);
		cur++;
	}
}

int main()
{
	init();
	solve();
	return 0;
}