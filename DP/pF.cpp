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

int n;
vector<int> spots;
int ans[100][100];

int dfs(int start, int end)
{
	if(end - start <= 1) return 0;

	int l, r;
	int mn = INF;
	for(int i = start + 1; i <= end - 1; i++)
	{
		l = (ans[start][i] == 0 ? dfs(start, i) : ans[start][i]);
		r = (ans[i][end] == 0 ? dfs(i, end) : ans[i][end]);

		if(l + r + spots[end] - spots[start] < mn)
		{
			mn = l + r + spots[end] - spots[start];
		}
	}

	ans[start][end] = mn;
	return mn;
}

void solve()
{
	int length;
	scanf("%d", &length);

	int temp;

	while(length > 0)
	{
		spots.clear();
		memset(ans, 0, sizeof(ans));

		scanf("%d", &n);
		spots.push_back(0);
		spots.push_back(length);
		for(int i = 0; i <= n - 1; i++)
		{
			scanf("%d", &temp);
			spots.push_back(temp);
		}
		sort(spots.begin(), spots.end());

		printf("The minimum cutting is %d.\n", dfs(0, n + 1));

		scanf("%d", &length);
	}
}

int main()
{
	init();
	solve();
	return 0;
}