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

int primes[100] = {0};

int isPrime(int x)
{
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0) return -1;
	}

	return 1;
}

void primeTable()
{
	int i = 2;
	primes[2] = 1;

	while(i < 100)
	{
		if(primes[i] == -1)
		{
			i++;
			continue;
		}
		else if(primes[i] == 1)
		{
			for(int j = 2; i * j < 100; j++)
			{
				primes[i * j] = -1;
			}

			i++;
		}
		else
		{
			primes[i] = isPrime(i);
		}
	}
}

int cur[100];
bool vstd[100] = {0};
int n;

void dfs(int lvl)
{
	if(lvl == 1)
	{
		cur[1] = 1;
		vstd[1] = true;
		dfs(2);
	}

	for(int i = 1; i <= n; i++)
	{
		if(!vstd[i])
		{
			cur[lvl] = i;

			if(isPrime(cur[lvl] + cur[lvl - 1]) == -1) continue;
			vstd[i] = true;

			if(lvl == n)
			{
				if(isPrime(cur[n] + 1) == 1)
				{
					for(int j = 1; j <= n; j++)
					{
						if(j != 1) printf(" ");
						printf("%d", cur[j]);
					}
					printf("\n");
				}
			}
			
			if(lvl < n) dfs(lvl + 1);
			vstd[i] = false;
		}
	}
}

void solve()
{
	primeTable();

	int nums[20];
	bool flag;
	int count = 1;
	int all = 0;
	int first[20];

	while(scanf("%d", &n) != EOF)
	{
		if(count > 1) printf("\n");
		printf("Case %d:\n", count);

		dfs(1);
		count++;
	}
}

int main()
{
	init();
	solve();
	return 0;
}