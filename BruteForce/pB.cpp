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
	vector<ll> vec;

	int n;
	int count = 1;
	ll temp;
	ll mx;

	while(scanf("%d", &n) != EOF)
	{
		vec.clear();
		mx = 0;

		for(int i = 0; i <= n - 1; i++)
		{
			scanf("%lld", &temp);
			vec.push_back(temp);
		}

		for(int i = 0; i <= n - 1; i++)
		{
			for(int j = i; j <= n - 1; j++)
			{
				temp = 1;
				for(int k = i; k <= j; k++)
				{
					temp *= vec[k];
				}
				if(temp > mx) mx = temp;
			}
		}

		printf("Case #%d: The maximum product is %lld.\n\n", count, mx);
		count++;
	}
}

int main()
{
	init();
	solve();
	return 0;
}