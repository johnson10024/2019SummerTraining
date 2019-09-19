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

class maxFlow
{

	int **cap;
	int *vstd;
	int *par;
	set<int> *mp;
	int vs;
	queue<int> que;
	bool flag;
	int s, e;

public:
	int ans;
	maxFlow(){};
	maxFlow(int n, int start, int end) //Numbers of node, start, end
	{
		vs = n;
		s = start;
		e = end;
		flag = true;
		ans = 0;
		vstd = new int[n + 10];
		par = new int[n + 10];
		mp = new set<int>[n + 10];
		cap = new int *[n + 10];
		memset(vstd, 0, sizeof(int) * (n + 10));
		for (int i = 0; i < n + 10; i++)
		{
			cap[i] = new int[n + 10];
			memset(cap[i], 0, sizeof(int) * (n + 10));
		}
	}

	void addEdge(int from, int to, int cp)
	{
		mp[from].insert(to);
		mp[to].insert(from);

		cap[from][to] += cp;
	}

	int exe()
	{
		int count = 1;
		int temp;
		int mn;
		flag = true;
		while (flag)
		{
			flag = false;

			que.push(s);
			vstd[s] = count;
			par[s] = -1;

			while (!que.empty())
			{
				temp = que.front();
				que.pop();

				if (flag)
					continue;

				if (temp == e)
				{
					flag = true;
					mn = INF;

					while (par[temp] != -1)
					{
						if (cap[par[temp]][temp] < mn)
							mn = cap[par[temp]][temp];
						temp = par[temp];
					}

					ans += mn;
					temp = e;
					while (par[temp] != -1)
					{
						cap[par[temp]][temp] -= mn;
						cap[temp][par[temp]] += mn;

						temp = par[temp];
					}

					continue;
				}

				for (set<int>::iterator v = mp[temp].begin(); v != mp[temp].end(); v++)
				{
					if (vstd[*v] != count && cap[temp][*v] > 0)
					{
						vstd[*v] = count;
						que.push(*v);
						par[*v] = temp;
					}
				}
			}

			count++;
		}

		return ans;
	}
};

void init()
{
}

void solve()
{
	int es, vs;
	int from, to, cp;

	while(scanf("%d %d", &es, &vs) != EOF)
	{
		maxFlow mf(vs, 1, vs);

		for(int i = 0; i <= es - 1; i++)
		{
			scanf("%d %d %d", &from, &to, &cp);
			mf.addEdge(from, to, cp);
		}

		printf("%d\n", mf.exe());
	}
}

int main()
{
	init();
	solve();
	return 0;
}