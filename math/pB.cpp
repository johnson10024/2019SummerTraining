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

ll fp(ll b, ll p, ll m)
{
	ll t = b;
	ll result = 1;

	t %= m;

	while (p)
	{
		if (p & 1)
		{
			result = (result * t) % m;
		}

		t = (t * t) % m;

		p >>= 1;
	}

	return result;
}

void init()
{
}

void solve()
{
	ll b, p, n;
	scanf("%lld %lld %lld", &b, &p, &n);

	ll x = fp(b, p, n);

	ll xi = 0, xi2 = 1, temp;
	for(ll i = 0; i <= x - 1; i++)
	{
		temp = (xi + xi2) % n;
		xi = xi2;
		xi2 = temp;
	}

	printf("%lld\n", xi);

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