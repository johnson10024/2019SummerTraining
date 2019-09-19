#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define INF (0x3f3f3f3f)

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int dp[15000];
int val[4000];
int w[4000];

void init()
{
	memset(dp, 0, sizeof(dp));
}

void solve()
{
	int n, wl;
	scanf("%d %d", &n, &wl);
	
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d %d", &w[i], &val[i]);
	}
	
	for(int i = 0; i <= n - 1; i++)
	{
		for(int j = wl; j >= 0; j--)
		{
			if(j - w[i] < 0) continue;
			
			dp[j] = max(val[i] + dp[j - w[i]], dp[j]);
		}
	}
	
	printf("%d\n", dp[wl]);
}

int main()
{
	init();
	solve();
}