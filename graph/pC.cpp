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

priority_queue< pair<int, pii>, vector< pair<int, pii> >, greater<pair<int, pii> > > pq;
int dist[2020];
vector<pii> mp[2020];

void init()
{
	memset(dist, INF, sizeof(dist));
}

void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int x, y, w;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		mp[x].push_back(make_pair(y, w));
		mp[y].push_back(make_pair(x, w));

	}

	dist[k] = 0;

	int sz = mp[k].size();
	int szpq = 0;
	pii p;

	pair<int, pii> temp;
	for(int i = 0; i <= sz - 1; i++)
	{
		p = mp[k][i];
		if(dist[k] + p.Y < dist[p.X])
		{
			dist[p.X] = dist[k] + p.Y;
			pq.push(make_pair(dist[p.X], make_pair(k, p.X)));
			szpq++;
		}
	}

	int from, to;
	while(szpq > 0)
	{
		temp = pq.top();
		from = temp.Y.X;
		to = temp.Y.Y;
		pq.pop();
		szpq--;

		sz = mp[to].size();
		for(int i = 0; i <= sz - 1; i++)
		{
			p = mp[to][i];
			if(dist[to] + p.Y < dist[p.X])
			{
				dist[p.X] = dist[to] + p.Y;
				pq.push(make_pair(dist[p.X], make_pair(to, p.X)));
				szpq++;
			}
		}
	}
// for(int i = 1; i <= k; i++) printf("%d ", dist[i]); printf("\n");
	printf("%d\n", dist[1]);
}

int main()
{
	init();
	solve();
	return 0;
}