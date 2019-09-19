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

int mp[1000][1000];
vector<pii> lrs;

void init()
{
}

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int q;
	int l, r;
	int lt, rt;
	int temp;
	bool flag;
	int mx;

	while(n + m > 0)
	{
		for(int i = 0; i <= n - 1; i++)
		{
			for(int j = 0; j <= m - 1; j++)
			{
				scanf("%d", &mp[i][j]);
			}
		}

		scanf("%d", &q);



		while(q--)
		{
			scanf("%d %d", &l, &r);

			for(int i = 0; i <= n - 1; i++)
			{
				lrs.push_back({lower_bound(mp[i], mp[i] + m, l) - mp[i], upper_bound(mp[i], mp[i] + m, r) - mp[i]});
// printf("%d %d\n", lrs[i].X, lrs[i].Y);
			}

			mx = 0;
			for(int i = 0; i <= n - 1; i++)
			{
				lt = lrs[i].X;
				rt = lrs[i].Y;
				temp = 0;

				for(int j = i; j <= n - 1; j++)
				{
					if(lrs[j].X >= lt && lrs[j].X <= rt) lt = lrs[j].X;
					if(lrs[j].Y <= rt) rt = lrs[j].Y;

					if(rt - lt > temp) temp++;
					else break;
				}

				if(temp > mx) mx = temp;
			}

			lrs.clear();
			printf("%d\n", mx);
		}

		scanf("%d %d", &n, &m);
		printf("-");
		// if(n + m > 0)
			printf("\n");
	}

}

int main()
{
	init();
	solve();
	return 0;
}