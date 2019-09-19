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

bool comp(pii p1, pii p2)
{
	if(p1.Y != p2.Y) return p1.Y < p2.Y;
	return p1.X < p2.X;
}

void solve()
{
	int n, t;
	scanf("%d %d", &n, &t);

	vector<pii> vec;

	int start, end;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d %d", &start, &end);
		vec.push_back(make_pair(start, end));
	}

	sort(vec.begin(), vec.end());

	start = 0;
	end = 0;

	if(t == 1 && vec[0].Y == 1)
	{
		printf("1\n");
		return;
	}

	int cur = 0;
	int ans = 0;
	int mx;
	bool flag;
	while(end < t)
	{
		flag = false;
		mx = end;
		while(cur < n && vec[cur].X <= end + 1)
		{
			if(vec[cur].X >= start && vec[cur].X <= end + 1 && vec[cur].Y >= end && vec[cur].Y >= mx)
			{
				mx = vec[cur].Y;
				flag = true;
			}

			cur++;
		}

		end = mx;
		
		if(!flag) break;
		ans++;
	}

	if(end >= t && flag) printf("%d\n", ans);
	else printf("-1\n");
}

int main()
{
	init();
	solve();
	return 0;
}