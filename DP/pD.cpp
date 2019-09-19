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

int dp[1010][1010];

void init()
{
	memset(dp, 0, sizeof(dp));
}

void solve()
{
	char inp1[10010];
	char inp2[10010];
	int l1, l2;

	while(fgets(inp1 + 1, 10010, stdin) != NULL)
	{
		fgets(inp2 + 1, 10010, stdin);

		l1 = strlen(inp1 + 1);
		l2 = strlen(inp2 + 1);

		if(inp1[l1] == '\n')
		{
			inp1[l1] = 0;
			l1--;
		}
		if(inp2[l1] == '\n')
		{
			inp2[l1] = 0;
			l2--;
		}

		if(l1 == 0 || l2 == 0)
		{
			printf("0\n");
			continue;
		}
		
		init();

		for(int i = 1; i <= l1; i++)
		{
			for(int j = 1; j <= l2; j++)
			{
				if(inp1[i] == inp2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		printf("%d\n", dp[l1][l2]);
	}
}

int main()
{
	init();
	solve();
	return 0;
}