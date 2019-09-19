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

vector<ll> vec;
vector<ll> times;

void solve()
{
	int b, n;
	scanf("%d %d", &b, &n);

	ll temp;
	for(int i = 1; i <= b; i++)
	{
		scanf("%lld", &temp);
		vec.push_back(temp);
	}

	times.push_back(vec[0] + 1);
	for(int i = 1; i <= b - 1; i++)
	{
		times.push_back(vec[i] + vec[n - 1] + 1);
	}

	int cur = 0;

	
}

int main()
{
	init();
	solve();
	return 0;
}