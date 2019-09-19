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

priority_queue<ll, vector<ll>, greater<ll> > pq;

void init()
{
}

void solve()
{
	int n;

	scanf("%d", &n);
	ll temp;
	ll x, y;
	ll ans;
	while(n > 0)
	{

		for(int i = 0; i <= n - 1; i++)
		{
			scanf("%lld", &temp);
			pq.push(temp);
		}

		ans = 0;

		while(!pq.empty())
		{
			x = pq.top();
			pq.pop();
			y = pq.top();
			pq.pop();

			ans += x + y;
			if(!pq.empty()) pq.push(x + y);
		}

		printf("%lld\n", ans);

		scanf("%d", &n);
	}
}

int main()
{
	init();
	solve();
	return 0;
}