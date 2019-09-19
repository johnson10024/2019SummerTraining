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
class UFDS
{
public:
	int *rep;

	UFDS(int n)
	{
		rep = (int *)malloc(n * sizeof(int));

		for (int i = 0; i <= n - 1; i++)
		{
			rep[i] = -1;
		}
	}

	bool merge(int x, int y)
	{
		int mn = find(x);
		int mx = find(y);
		if (mn == mx)
			return false;
		if (rep[mn] < rep[mx])
			swap(mx, mn);

		rep[mx] += rep[mn];
		rep[mn] = mx;

		return true;
	}

	int find(int x)
	{
		if (rep[x] < 0)
			return x;
		return rep[x] = find(rep[x]);
	}
};

class edge{
public:
	int from, to, w;

	edge(){};

	edge(int x, int y, int  W)
	{
		from = x;
		to = y;
		w = W;
	}

	bool operator <(edge &e2)
	{
		return w < e2.w;
	}
};

int N;
vector<int> mp[10010];
vector<edge> vec;
bool vstd[10010];
queue<int> que;

void init()
{
	for(int i = 0; i < 10010; i++)
	{
		mp[i].clear();
	}
	vec.clear();

	memset(vstd, 0, sizeof(vstd));
}

void solve(int fuckPresentation)
{
	int n, m, a;
	scanf("%d %d %d", &n, &m, &a);

	int air = 0;
	int x, y, c;
	for(int i = 0; i <= m - 1; i++)
	{
		scanf("%d %d %d", &x, &y, &c);

		if(c < a)
		{
			vec.push_back(edge(x, y, c));
			mp[x].push_back(y);
			mp[y].push_back(x);
		}
	}
	sort(vec.begin(), vec.end());

	int temp;
	for(int i = 1; i <= n; i++)
	{
		if(!vstd[i])
		{
			air++;
			que.push(i);
			vstd[i] = true;

			while(!que.empty())
			{
				temp = que.front();
				que.pop();
				for(int v : mp[temp])
				{
					if(!vstd[v])
					{
						que.push(v);
						vstd[v] = true;
					}
				}
			}
		}
	}

	int ans = 0;

	UFDS ufds(n + 10);

	for(edge e : vec)
	{
		if(ufds.find(e.from) != ufds.find(e.to))
		{
			ans += e.w;
			ufds.merge(e.from, e.to);
		}
	}

	printf("Case #%d: %d %d\n", fuckPresentation, ans + a * air, air);
}

int main()
{
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
	{
		init();
		solve(i);
	}

	return 0;
}