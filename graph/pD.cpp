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

class edge{
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

int dist[3000];

vector<edge> vec;

void init()
{
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	vec.clear();
}

void solve()
{
	int n, m, w;
	scanf("%d %d %d", &n, &m, &w);

	int x, y, c;
	int index;
	for(int i = 0; i <= m - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		vec.push_back(edge(x, y, c));
		vec.push_back(edge(y, x, c));
	}

	for(int i = 0; i <= w - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		vec.push_back(edge(x, y, -c));
	}

	dist[vec[0].from] = 0;
	vector<edge>::iterator it;
	for(int i = 0; i <= m + w - 2; i++)
	{
		for(it = vec.begin(); it != vec.end(); it++)
		{
			if(dist[it -> from] + it -> cost < dist[it -> to])
			{
				dist[it -> to] = dist[it -> from] + it -> cost;
			}
		}
	}

	bool flag = false;
	for(it = vec.begin(); it != vec.end(); it++)
	{
		if(dist[it -> from] + it -> cost < dist[it -> to])
		{
			flag = true;
			break;
		}
	}

	if(flag) printf("YES\n");
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