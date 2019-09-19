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

void solve()
{
	int n;
	scanf("%d", &n);

	vector<int> vec;
	int temp;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
	}
	
	sort(vec.begin(), vec.end());

	scanf("%d", &n);
	vector<int>::iterator it;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d", &temp);
		it = upper_bound(vec.begin(), vec.end(), temp);

		printf("%d\n", (int)(it - vec.begin()));
	}
}

int main()
{
	init();
	solve();
	return 0;
}