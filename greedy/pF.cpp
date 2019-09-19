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

bool cmpp(pii p1, pii p2)
{
	if(p1.Y != p2.Y) return p1.Y < p2.Y;
	else return p1.X < p2.X;
}

bool comp(pii p1, pii p2)
{
	pii p1t = p1;
	pii p2t = p2;

	if(p1t.X > p1t.Y) swap(p1t.X, p1t.Y);
	if(p2t.X > p2t.Y) swap(p2t.X, p2t.Y);

	return cmpp(p1t, p2t);
}

vector<pii> real;
vector<pii> vec;
vector<pii> ans;

void init()
{
	real.clear();
	vec.clear();
	ans.clear();
}

void solve()
{
	int n;
	scanf("%d", &n);

	int count = 0;
	int x, y;
	scanf("%d %d", &x, &y);

	while(x != 0 || y != 0)
	{
		real.push_back(make_pair(x, y));
		if(x > y) swap(x, y);
		vec.push_back(make_pair(x, y));
		count++;
		scanf("%d %d", &x, &y);
	}
	sort(vec.begin(), vec.end(), cmpp);
	sort(real.begin(), real.end(), comp);

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

	int start, end;
	start = -INF;
	end = -1;

	int mxi = cur;
	bool flag;

	while(end < n)
	{
		flag = false;
		while(cur < count && vec[cur].X <= end + 1)
		{
			if(vec[cur].Y >= end && vec[cur].Y >= vec[mxi].Y || mxi == cur)
			{
				/*if(vec[cur].Y >= n)
				{
					if(vec[mxi].Y < n) mxi = cur;
					else
					{
						if(vec[cur].Y < vec[mxi].Y) mxi = cur;
					}
				}
				else//*/
				{
					mxi = cur;
				}
				flag = true;
			}

			cur++;
		}

		end = vec[mxi].Y;
		if(!flag) break;

		ans.push_back(vec[mxi]);
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
		if(n > 0)
		printf("\n");
	}
	return 0;
}