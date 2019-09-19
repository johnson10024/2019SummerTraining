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

map<int, int> mp;

void init()
{
	mp.clear();
}

void solve()
{
	int n;
	scanf("%d", &n);

	int mx = 0;
	int start = 0;

	int temp;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d", &temp);
		if(mp.find(temp) != mp.end() && mp[temp] >= start)
		{
			if(i - start > mx) mx = i - start;
			start = mp[temp] + 1;
		}

		mp[temp] = i;
		
	}
// printf("start=%d\n", start);
	if(n - start > mx) mx = n - start;

	printf("%d\n", mx);
	
}

int main()
{
	int n;
	scanf("%d", &n);

	while(n--)
	{
		init();
		solve();
		// if(n > 0) printf("\n");
	}

	return 0;
}