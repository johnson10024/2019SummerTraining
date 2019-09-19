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

class node{
	public:

	int from;
	int to;
	int w;

	bool operator <(node &n2)
	{
		return w < n2.w;
	}
};

vector<node> mp;


void init()
{
}

void solve()
{
	int n;
	scanf("%d", &n);

	char from[10];
	char to[10];
	int w;
	int l;
	int sz;
	node temp;

	int count = 0;
	int cur = 0;
	int ans = 0;

	while(n > 0)
	{
		count = 0;
		ans = 0;
		cur = 0;
		mp.clear();

		for(int i = 0; i < n - 1; i++)
		{
			scanf("%s %d", from, &l);

			for(int j = 0; j <= l - 1; j++)
			{
				scanf("%s %d", to, &w);
				
				temp.from = from[0] - 'A';
				temp.to = to[0] - 'A';
				temp.w = w;
				mp.push_back(temp);
			}
		}

		sort(mp.begin(), mp.end());
		sz = mp.size();

		UFDS ufds(100);
		
		while(count < n - 1)
		{
			if(ufds.find(mp[cur].from) != ufds.find(mp[cur].to))
			{
				ufds.merge(mp[cur].to, mp[cur].from);
				count++;
				ans += mp[cur].w;
			}

			cur++;
		}

		printf("%d\n", ans);
		scanf("%d", &n);
	}
}

int main()
{
	init();
	solve();
	return 0;
}