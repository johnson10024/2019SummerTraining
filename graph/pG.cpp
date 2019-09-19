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

vector<int> mp[1010];
queue<int> que;
int par[1010];
int pr[1010];
int vstd[1010];

void init()
{
	memset(par, 0, sizeof(par));
	memset(pr, 0, sizeof(pr));
	for(int i = 0; i < 1010; i++)
	{
		mp[i].clear();
	}
}

void solve()
{
	int k, g, b;
	scanf("%d", &k);

	int from, to;
	int count = 0;
	bool fnd = false;
	int temp, x;
	int ans = 0;
	while(k)
	{
		init();

		scanf("%d %d", &g, &b);
		ans = 0;
		count = 0;

		for(int i = 0; i <= k - 1; i++)
		{
			scanf("%d %d", &from, &to);
			mp[from].push_back(to + g);
			mp[to + g].push_back(from);
		}
		
		for(int i = 1; i <= g; i++)
		{
			if(pr[i]) continue;

			que.push(i);
			vstd[i] = i;
			par[i] = -1;

			fnd = false;
			while(!que.empty())
			{
				temp = que.front();
				que.pop();
				if(fnd) continue;

				for(int v : mp[temp])
				{
					if(vstd[v] != i)
					{
						vstd[v] = i;
						if(pr[v])
						{
							par[pr[v]] = temp;
							que.push(pr[v]);
						}
						else
						{
							fnd = true;

							while(temp != -1)
							{
								x = pr[temp];
								pr[temp] = v;
								pr[v] = temp;

								temp = par[temp];
								v = x;
							}

							ans++;
							break;
						}
					}
				}
			}

		}

		printf("%d\n", ans);
		scanf("%d", &k);
	}

}

int main()
{
	init();
	solve();
	return 0;
}