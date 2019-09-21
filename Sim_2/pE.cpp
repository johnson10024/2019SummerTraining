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

vector<pii> vec;
vector<int> ans;
map<pii, int> mp;
bool comp(pii p1, pii p2)
{
	return p1.Y > p2.Y;
}

void solve()
{
	int n;
	pii p;
	scanf("%d", &n);

	int c, r;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &c, &r);
		vec.push_back({c, r});
		mp[{c, r}] = i;
	}

	int cf, rf;
	cf = c;
	rf = r;

	c = 0, r = 1;
	vec.pop_back();
	sort(vec.begin(), vec.end());

	vector<pii>::iterator it;
	vector<pii>::iterator start = vec.begin();
	vector<pii>::iterator mx = vec.begin();
	bool flag = true;
	while(r < cf && start != vec.end())
	{
		it = upper_bound(start, vec.end(), make_pair(r, (int)1e9 + 7));
		if(it == vec.begin())
		{
			flag = false;
			break;
		}
		
		for(vector<pii>::iterator cur = start; cur != it; cur++)
		{
			if(cur -> Y > mx -> Y) mx = cur;
		}

		if((it == vec.end() && mx -> Y < cf) || mx -> Y < it -> X)
		{
			flag = false;
			break;
		}

		c = mx -> X;
		r = mx -> Y;
		ans.push_back(mp[*mx]);
		start = it;
	}

	if(!flag || r < cf)
	{
		printf("No such luck\n");
		return;
	}
	
	printf("%d\n", (int)ans.size() + 1);
	for(int i : ans)
	{
		printf("%d ", i);
	}
	printf("%d\n", n);
}

int main()
{
	init();
	solve();
	return 0;
}