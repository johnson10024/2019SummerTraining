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

vector<int> vec;

void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);

	double temp;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%lf", &temp);
		vec.push_back((int)(temp * 100));
	}

	int mn = 1, mx = 1e8;
	int mid = (mx + mn) / 2;

	int sum;
	while(mx - mn > 1)
	{
		sum = 0;
		for(int i = 0; i <= n - 1; i++)
		{
			sum += vec[i] / mid;
		}

		if(sum < k) mx = mid;
		else mn = mid;

		mid = (mx + mn) / 2;
	}

	sum = 0;
	for(int i = 0; i <= n - 1; i++)
	{
		sum += vec[i] / mx;
	}

	if(sum >= k) printf("%.2lf\n", (double)mx / 100.0);
	else
	{
		sum = 0;
		for(int i = 0; i <= n - 1; i++)
		{
			sum += vec[i] / mn;
		}

		if(sum >= k) printf("%.2lf\n", (double)mn / 100.0);
		else printf("0.00\n");
	}
}

int main()
{
	init();
	solve();
	return 0;
}