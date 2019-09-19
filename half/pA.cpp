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

vector<ll> aa;
vector<ll> bb;
vector<ll> cc;
vector<ll> dd;
vector<ll> ab;
vector<ll> cds;

void init()
{
}

void solve()
{
	int n;
	scanf("%d", &n);

	ll a, b, c, d;

	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		aa.push_back(a);
		bb.push_back(b);
		cc.push_back(c);
		dd.push_back(d);
	}

	int sa = aa.size();
	int sb = bb.size();
	int sc = cc.size();
	int sd = dd.size();

	for(int i = 0; i <= sa - 1; i++)
	{
		for(int j = 0; j <= sb - 1; j++)
		{
			ab.push_back(aa[i] + bb[j]);
		}
	}

	for(int i = 0; i <= sc - 1; i++)
	{
		for(int j = 0; j <= sd - 1; j++)
		{
			cds.push_back(cc[i] + dd[j]);
		}
	}

	int sab = ab.size();
	int scd = cds.size();

	sort(cds.begin(), cds.end());

	int ans = 0;
	vector<ll>::iterator it;
	for(int i = 0; i <= sab - 1; i++)
	{
		ans += (int)(upper_bound(cds.begin(), cds.end(), -ab[i]) - lower_bound(cds.begin(), cds.end(), -ab[i]));
	}

	printf("%d\n", ans);

}

int main()
{
	init();
	solve();
	return 0;
}