#include <algorithm>
#include <cstdio>
#include <iostream>
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

int nums[10];

void init()
{
	memset(nums, 0, sizeof(nums));
}

void solve()
{
	int n;
	scanf("%d", &n);

	if(n == 1)
	{
		printf("1\n");
		return;
	}
	
	for(int i = 9; i >= 2; i--)
	{
		while(n % i == 0)
		{
			nums[i]++;
			n /= i;
		}
	}

	if(n > 1)
	{
		printf("-1\n");
		return;
	}

	for(int i = 2; i <= 9; i++)
	{
		while(nums[i]--) printf("%d", i);
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		init();
		solve();
	}

	return 0;
}