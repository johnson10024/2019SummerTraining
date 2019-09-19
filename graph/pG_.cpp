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

class matching
{
	vector<int> *mp;
	queue<int> que;
	int *vstd;
	int *par;
	bool fnd;
	int l, r;

public:
	int *match;
	int ans = 0;

	matching(int left, int right)
	{
		l = left;
		r = right;

		mp = new vector<int>[l + r + 10];
		vstd = new int[l + r + 10];
		match = new int[l + r + 10];
		par = new int[l + r + 10];

		memset(vstd, 0, sizeof(int) * (l + r + 10));
		memset(match, 0, sizeof(int) * (l + r + 10));
	}

	void addEdge(int from, int to) //l = 1-indexed, r = 1-indexed, no reverse
	{
		mp[from].push_back(to + l);
		mp[to + l].push_back(from);
	}

	int exe()
	{
		int temp, x;
		for (int i = 1; i <= l; i++)
		{
			if (match[i])
				continue;

			que.push(i);
			vstd[i] = i;
			par[i] = -1;

			fnd = false;
			while (!que.empty())
			{
				temp = que.front();
				que.pop();

				if (fnd)
					continue;

				for (int v : mp[temp])
				{
					if (vstd[v] != i)
					{
						vstd[v] = i;

						if (match[v])
						{
							par[match[v]] = temp;
							que.push(match[v]);
						}
						else
						{
							fnd = true;

							while (temp != -1)
							{
								x = match[temp];
								match[temp] = v;
								match[v] = temp;

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

		return ans;
	}
};

void init()
{
}

void solve()
{
	int k, g, b;
	scanf("%d", &k);

	int from, to;

	while(k)
	{
		scanf("%d %d", &g, &b);

		matching mat(g, b);
		for(int i = 0; i <= k - 1; i++)
		{
			scanf("%d %d", &from, &to);
			mat.addEdge(from, to);
		}

		printf("%d\n", mat.exe());

		scanf("%d", &k);
	}
}

int main()
{
	init();
	solve();
	return 0;
}