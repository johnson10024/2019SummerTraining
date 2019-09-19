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

void init()
{
}

void solve()
{
	int n;
	scanf("%d", &n);

	int N = n;

	int cur = 2;
	int sum = 0;
	vector<int> ans;
	
	while(n >= cur)
	{
		ans.push_back(cur);
		sum += cur;
		n -= cur;
		cur++;
	}
	n = N - sum;

	int sz = ans.size();
// printf("//%d\n", n % sz);
	for(int i = sz - 1; i >= 0; i--)
	{
		if(i >= sz - (n % sz) && (n % sz)) ans[i]++;
		ans[i] += n / sz;
	}

	for(int i = 0; i <= sz - 1; i++)
	{
		if(i > 0) printf(" ");
		printf("%d", ans[i]);
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
		if(n > 0)
		 printf("\n");
	}

	return 0;
}