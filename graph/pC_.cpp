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
class dijkstra
{

	priority_queue<pii, vector<pii>, greater<pii> > pq;
	vector<pii> *mp;
	vector<pii>::iterator it;
	int s;
	pii temp;

public:
	int *dist;
	dijkstra(int v, int sv)
	{
		s = sv;

		dist = new int[v + 10];
		memset(dist, INF, sizeof(int) * (v + 10));
		dist[s] = 0;

		mp = new vector<pii>[v + 10];
	}

	void addEdge(int from, int to, int weight)
	{
		mp[from].push_back({to, weight});
	}

	void exe()
	{
		for (it = mp[s].begin(); it != mp[s].end(); it++)
		{
			if (it ->Y < dist[it ->X])
			{
				dist[it ->X] = it ->Y;
				pq.push({dist[it ->X], it ->X});
			}
		}

		while (!pq.empty())
		{
			temp = pq.top();
			pq.pop();

			for (it = mp[temp.Y].begin(); it != mp[temp.Y].end(); it++)
			{
				if (dist[temp.Y] + it -> Y < dist[it -> X])
				{
					dist[it -> X] = dist[temp.Y] + it -> Y;
					pq.push({dist[it -> X], it -> X});
				}
			}
		}
	}
};

void init()
{
}

void solve()
{
	int t, n;
	scanf("%d %d", &t, &n);

	dijkstra dij(n, 1);

	int x, y, w;
	for(int i = 0; i <= t - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &w);
		dij.addEdge(x, y, w);
		dij.addEdge(y, x, w);
	}

	dij.exe();
	printf("%d\n", dij.dist[n]);
}

int main()
{
	init();
	solve();
	return 0;
}