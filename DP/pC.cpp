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

int dp[8000];
int val[] = {1, 5, 10, 25, 50};

void init()
{
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
}

void solve()
{
	for(int i = 0; i <= 4; i++)
	{
		for(int j = val[i]; j <= 7500; j++)
		{
			dp[j] = dp[j] + dp[j - val[i]];
		}
	}


	int n;

	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n", dp[n]);
	}
}

int main()
{
	init();
	solve();
	return 0;
}