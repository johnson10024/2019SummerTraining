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

vector<pii> vec;
vector<pii> ans;

bool comp(pii p1, pii p2)
{
	if(p1.Y != p2.Y) return p1.Y < p2.Y;
	// return p1.X < p2.X;
}

void init()
{
	vec.clear();
	ans.clear();
}

void solve()
{
	int n;
	scanf("%d", &n);

	int x, y;
	int count = 0;
	scanf("%d %d", &x, &y);

	while(x != 0 || y != 0)
	{
		vec.push_back(make_pair(x, y));
		count++;

		scanf("%d %d", &x, &y);
	}
	sort(vec.begin(), vec.end());
	
	int cur = 0;
	while(cur < count && vec[cur].Y < 0)
	{
		cur++;
	}

	if(cur >= count || vec[cur].X > 0)
	{
		printf("0\n");
		return;
	}

	sort(vec.begin() + cur, vec.end());
	int end = 0;
	int mxi = cur;
	bool flag = false;
	bool arr = false;

	while(end < n)
	{
		flag = false;
		while(cur < count && vec[cur].X <= end)
		{
			if(vec[cur].X >= n)
			{
				arr = true;
				mxi = cur;
				break;
			}
			if(vec[cur].Y >= vec[mxi].Y || mxi == cur)
			{
				flag = true;
				mxi = cur;
			}

			cur++;
		}

		if(!flag) break;
		end = vec[mxi].Y;
		ans.push_back(vec[mxi]);
		if(arr) break;
	}


	if(end < n) printf("0\n");
	else
	{
		sort(ans.begin(), ans.end());

		printf("%d\n", (int)ans.size());
		for(pii p : ans)
		{
			printf("%d %d\n", p.X, p.Y);
		}
	}

}

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		init();
		solve();

		if(n)
			printf("\n");
	}

	return 0;
}