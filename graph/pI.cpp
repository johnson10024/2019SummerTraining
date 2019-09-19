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

vector<int> vec[100010];
int lvl[100010];
int par[100010];
bool vstd[100010];
queue<int> que;

void init()
{
	memset(vstd, 0, sizeof(vstd));
	memset(lvl, 0, sizeof(lvl));
	for(int i = 0; i < 100010; i++)
	{
		vec[i].clear();
	}
}

void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int to, from;
	for(int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &to, &from);
		vec[from].push_back(to);
		vec[to].push_back(from);
	}

	int temp;
	int cur = 1;
	que.push(1);
	vstd[1] = true;
	while(!que.empty())
	{
		temp = que.front();
		que.pop();

		for(int i : vec[temp])
		{
			if(!vstd[i])
			{
				vstd[i] = true;
				que.push(i);
				lvl[i] = lvl[temp] + 1;
				if(lvl[i] > lvl[cur]) cur = i;
			}
		}
	}

	memset(vstd, 0, sizeof(vstd));
	lvl[cur] = 0;
	par[cur] = cur;
	
	que.push(cur);
	vstd[cur] = true;

	while(!que.empty())
	{
		temp = que.front();
		que.pop();

		for(int i : vec[temp])
		{
			if(!vstd[i])
			{
				vstd[i] = true;
				que.push(i);
				lvl[i] = lvl[temp] + 1;
				if(lvl[i] > lvl[cur]) cur = i;
				par[i] = temp;
			}
		}
	}

	int nodes = 0;
	for(int i = 0; i <= k - 1; i++)
	{
		scanf("%d", &temp);
		if(temp <= lvl[cur])
		{
			printf("%d\n", temp - 1);
		}
		else
		{
			printf("%d\n", lvl[cur] + (temp - (lvl[cur] + 1)) * 2);
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
	}

	return 0;
}