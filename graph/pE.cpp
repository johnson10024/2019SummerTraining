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

int dist[500][500];

void init()
{
	memset(dist, INF, sizeof(dist));
	for(int i = 0; i < 500; i++)
	{
		dist[i][i] = 0;
	}
}

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> mov;
	int count;
	int temp;
	for(int i = 0; i <= m - 1; i++)
	{
		scanf("%d", &count);
		mov.clear();

		for(int j = 0; j <= count - 1; j++)
		{
			scanf("%d", &temp);
			mov.push_back(temp);
		}

		for(int j = 0; j <= count - 1; j++)
		{
			for(int s = j + 1; s <= count - 1; s++)
			{
				dist[mov[j]][mov[s]] = 1;
				dist[mov[s]][mov[j]] = 1;
			}
		}
	}
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int sum;
	int mn = INF;
	for(int i = 1; i <= n; i++)
	{
		sum = 0;
		for(int j = 1; j <= n; j++)
		{
			sum += dist[i][j];
		}
		if(sum < mn) mn = sum;
	}

	printf("%d\n", mn * 100 / (n - 1));
}

int main()
{
	init();
	solve();
	return 0;
}