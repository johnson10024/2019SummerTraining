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

char inp[100100];
int tinp[100100] = {0};
int all[100100] = {0};

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int temp;
	int ones = 0;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%s", inp);
		temp = 0;
		for(int j = 0; j <= m - 1; j++)
		{
			if(inp[j] == '.') tinp[j]++;
			else
			{
// printf("%d..", tinp[j]);
				for(int k = 2; k <= tinp[j]; k++)
				{
					all[k] += tinp[j] - k + 1;
				}
				tinp[j] = 0;
			}

			if(inp[j] == '.')
			{
				ones++;
				temp++;
			}
			else
			{
				for(int k = 2; k <= temp; k++)
				{
					all[k] += temp - k + 1;
				}
				temp = 0;
			}
		}

		for(int k = 2; k <= temp; k++)
		{
			all[k] += temp - k + 1;
		}
	}

	for(int i = 0; i <= m - 1; i++)
	{
// printf("%d..", tinp[i]);
		for(int k = 2; k <= tinp[i]; k++)
		{
			all[k] += tinp[i] - k + 1;
		}
	}

	int p = max(m, n);

	printf("%d", ones);
	for(int i = 2; i <= p; i++)
	{
		printf(" %d", all[i]);
	}
	printf("\n");
}

int main()
{
	init();
	solve();
	return 0;
}