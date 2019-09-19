#include <algorithm>
#include <cstdio>
#include <iostream>
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

class edge
{
public:
	int from, to, cost;

	edge(){};
	edge(int x, int y, int c)
	{
		from = x;
		to = y;
		cost = c;
	}
};

class bellmanFord
{
	int s;
	int n;
	vector<edge> vec;

public:
	int haveNeg; // -1: Not executed yet; 0: No; 1: Yes
	int *dist;

	bellmanFord(){};
	bellmanFord(int nv, int sv)
	{
		haveNeg = -1;
		n = nv;
		s = sv;
		dist = (int *)malloc(sizeof(int) * (n + 10));
		memset(dist, INF, sizeof(int) * (n + 10));
		dist[sv] = 0;
	}

	void addEdge(int x, int y, int c)
	{
		vec.push_back(edge(x, y, c));
	}

	void exe()
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (vector<edge>::iterator it = vec.begin(); it != vec.end(); it++)
			{
				if (dist[it -> from] + it -> cost < dist[it -> to])
				{
					dist[it -> to] = dist[it -> from] + it -> cost;
				}
			}
		}

		bool flag = false;
		for (vector<edge>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			if (dist[it -> from] + it -> cost < dist[it -> to])
			{
				flag = true;
				break;
			}
		}

		if (flag)
			haveNeg = 1;
		else
			haveNeg = 0;
	}
};

void init()
{
}

void solve()
{
	int n, m, w;
	scanf("%d %d %d", &n, &m, &w);

	bellmanFord bell(n, 1);

	int x, y, c;
	for(int i = 0; i <= m - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		bell.addEdge(x, y, c);
		bell.addEdge(y, x, c);
	}

	for(int i = 0; i <= w - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		bell.addEdge(x, y, -c);
	}

	bell.exe();

	if(bell.haveNeg) printf("YES\n"); 
	else printf("NO\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		init();
		solve();
	}

	return 0;
}