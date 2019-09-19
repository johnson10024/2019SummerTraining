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

int cap[300][300];
int vstd[300] = {0};
int par[300];
set<int> mp[300];

void init()
{
	memset(cap, 0, sizeof(cap));
	memset(vstd, 0, sizeof(vstd));
	for(int i = 0; i < 300; i++)
	{
		mp[i].clear();
	}
}

void solve()
{
	int es, vs;
	

	int ans = 0;
	int count = 1;
	int temp;
	int cur;
	int mn;
	bool flag = true;
	queue<int> que;

	int from, to, cp;

	while(scanf("%d %d", &es, &vs) != EOF)
	{
		init();

		flag = true;
		ans = 0;
		count = 1;
		for(int i = 0; i <= es - 1; i++)
		{
			scanf("%d %d %d", &from, &to, &cp);
			cap[from][to] += cp;
			mp[from].insert(to);
			mp[to].insert(from);
		}

		while(flag)
		{
			flag = false;

			que.push(1);
			vstd[1] = count;
			par[1] = -1;

			while(!que.empty())
			{
				temp = que.front();
				que.pop();

				if(flag) continue;

				if(temp == vs)
				{
					flag = true;
					mn = INF;

					while(par[temp] != -1)
					{
						if(cap[par[temp]][temp] < mn) mn = cap[par[temp]][temp];
						temp = par[temp];
					}
					temp = vs;
					ans += mn;

					while(par[temp] != -1)
					{
						cap[par[temp]][temp] -= mn;
						cap[temp][par[temp]] += mn;

						temp = par[temp];
					}

					continue;
				}

				for(set<int>::iterator v = mp[temp].begin(); v != mp[temp].end(); v++)
				{
					if(vstd[*v] != count && cap[temp][*v] > 0)
					{
						vstd[*v] = count;
						que.push(*v);
						par[*v] = temp;
					}
				}
			}

			count++;
		}

		printf("%d\n", ans);
	}
}

int main()
{
	init();
	solve();
	return 0;
}