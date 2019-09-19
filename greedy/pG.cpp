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

vector<pii> vec;
vector<pii> ans;

bool comp(pii p1, pii p2)
{
	if(p1.Y != p2.Y)
		return p1.Y < p2.Y;

	// return p1.X < p2.X;
	return (p1.Y - p1.X) < (p2.Y - p2.X);
}

void init()
{
}

void solve()
{
	int n;
	scanf("%d", &n);
	int start, end;
	bool flag;

	while(n > 0)
	{
		ans.clear();
		vec.clear();
		for(int i = 0; i <= n - 1; i++)
		{
			scanf("%d %d", &start, &end);
			vec.push_back(make_pair(start, end));
		}

		sort(vec.begin(), vec.end(), comp);
// for(pii p : vec) printf("%d %d\n", p.X, p.Y);
		for(pii p : vec)
		{
// printf("%d %d\n", p.X, p.Y);
			flag = true;
			for(pii pp : ans)
			{
				if(!((p.X <= pp.X && p.Y <= pp.X) || (p.X >= pp.Y && p.Y >= pp.Y)))
				{
					flag = false;
					break;
				}
			}

			if(flag)
			{
				ans.push_back(p);
			}
		}

		printf("%d\n", (int)ans.size());

		scanf("%d", &n);
	}
}

int main()
{
	init();
	solve();
	return 0;
}