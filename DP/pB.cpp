#include <algorithm>
#include <iostream>
#include <cstdio>
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

int dp[10010];
int val[550];
int w[550];

void init()
{
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
}

void solve()
{
	int emp, ful;
	scanf("%d %d", &emp, &ful);
	
	ful -= emp;
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d %d", &val[i], &w[i]);
	}

	for(int i = 0; i <= n - 1; i++)
	{
		for(int j = w[i]; j <= ful; j++)
		{
			if(val[i] + dp[j - w[i]] < dp[j]) dp[j] = val[i] + dp[j - w[i]];
		}
	}
	
	if(dp[ful] == INF) printf("This is impossible.\n");
	else printf("The minimum amount of money in the piggy-bank is %d.\n", dp[ful]);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	while(n--)
	{
		init();
		solve();
	}
	
	return 0;
}