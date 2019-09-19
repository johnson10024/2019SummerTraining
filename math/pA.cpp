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

int fp(int b, int p, int m)
{
	int t = b;
	int result = 1;

	t %= m;

	while(p)
	{
		if(p & 1)
		{
			result = (result * t) % m;
		}

		t = (t * t) % m;

		p >>= 1;
	}

	return result;
}

void init()
{
}

void solve()
{
	int b, p, m;
// printf("%d\n", fp(2, 10, MOD));
	while(scanf("%d %d %d", &b, &p, &m) != EOF)
	{
		printf("%d\n", fp(b, p, m));
	}


}

int main()
{
	init();
	solve();
	return 0;
}