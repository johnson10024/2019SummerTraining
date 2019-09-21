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

void init()
{
}

vector<ll> sss;
vector<ll> num;
map<ll, int> mp;

void solve()
{
	int n;
	sss.push_back(0ll);
	num.push_back(0ll);
	mp[0ll] = 0;
	scanf("%d", &n);
	int a, b = INF;

	ll temp;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &temp);

		if(temp == 0ll)
		{
			a = i;
			b = 1;
			continue;
		}

		num.push_back(temp);
		sss.push_back(temp + sss[i - 1]);
		if(mp.find(sss[i]) != mp.end())
		{
			if(i - mp[sss[i]] < b)
			{
				a = mp[sss[i]] + 1;
				b = i - mp[sss[i]];
			}
		}
		mp[sss[i]] = i;
	}

	if(b == INF)
	{
		printf("-1\n");
		return;
	}

	printf("%d %d\n", a, b);

}

int main()
{
	init();
	solve();
	return 0;
}