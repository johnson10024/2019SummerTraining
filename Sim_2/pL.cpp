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

void solve()
{
	ll x, y;
	scanf("%lld %lld", &x, &y);
	if(x == 1ll && y == 1ll)
	{
		printf("1\n");
		return;
	}
	if(x == 1ll || y == 1ll)
	{
		printf("2\n");
		return;
	}

	if(x > y) swap(x, y);

	ll t = y;
	ll tx = 1;
	ll mn, mx;
	ll mid;
	ll temp;
	while(1)
	{
		mn = 1;
		mx = t;
		mid = (t + tx) / 2;

		while(mx - mn > 1)
		{
			if(x * mid > t) mx = mid;
			else mn = mid;

			mid = (mx + mn) / 2;
		}
		tx = mid;

		if(x * mx <= t) temp = mx;
		else temp = mn;

		if(y - x * temp <= 1) break;

		t += y;
	}

	printf("%lld\n", t);
}

int main()
{
	init();
	solve();
	return 0;
}