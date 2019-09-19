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

pii edge[80800];
int dis[80800] = {0};
int vstd[400] = {0};

int val[80800];
int pars[400];

vector<int> mp[1000];
set<int> alws;
vector<int> alw;
queue<int> que;

void init()
{
}

void solve()
{
	int n, es, t;

	scanf("%d %d %d", &n, &es, &t);

	int from, to, w;
	int count = 0;
	for(int i = 0; i <= es - 1; i++)
	{
		scanf("%d %d %d", &from, &to, &w);
		edge[count] = make_pair(from, to);
		val[count] = w;
		mp[from].push_back(count++);

		edge[count] = make_pair(to, from);
		val[count] = w;
		mp[to].push_back(count++);

		alws.insert(w);
	}
	for(set<int>::iterator it = alws.begin(); it != alws.end(); it++)
	{
		alw.push_back(*it);
	}

// printf("%d\n", count);for(int i = 1; i <= 7; i++) for(int j : mp[i]) printf("edge %d: %d -> %d\n", j, edge[j].X, edge[j].Y);
	
	int mx = alw.size() - 1;
	int mn = 0;
	int mid = (mx + mn) / 2;

	vector<int>::iterator it;
	int temp;

	bool flag;
	count = 1;
	int discnt = 1;

	while(mx - mn > 1)
	{
		flag = true;

		for(int i = 0; i <= t - 1; i++)
		{
			vstd[1] = count;
			pars[1] = -1;
			for(it = mp[1].begin(); it != mp[1].end(); it++)
			{
				to = edge[*it].Y;
				if(vstd[to] != count && dis[*it] != discnt && val[*it] <= alw[mid])
				{
					que.push(*it);
					vstd[to] = count;
					pars[to] = *it;
				}
			}

			while(!que.empty())
			{
				temp = que.front();
				from = edge[temp].Y;
				que.pop();

				if(from == n) break;

				for(it = mp[from].begin(); it != mp[from].end(); it++)
				{
					to = edge[*it].Y;
					if(vstd[to] != count && dis[*it] != discnt && val[*it] <= alw[mid])
					{
						que.push(*it);
						vstd[to] = count;
						pars[to] = *it;
					}
				}

			}

			while(!que.empty()) que.pop();

			if(vstd[n] != count)
			{
				flag = false;
				break;
			}

			while(temp != -1)
			{
				dis[temp] = discnt;
				temp = pars[edge[temp].X];
			}

			count++;
		}

		discnt++;

		if(flag) mx = mid;
		else mn = mid;

		mid = (mx + mn) / 2;
	}

	flag = true;

	for(int i = 0; i <= t - 1; i++)
	{
		vstd[1] = count;
		pars[1] = -1;
		for(it = mp[1].begin(); it != mp[1].end(); it++)
		{
			to = edge[*it].Y;
			if(vstd[to] != count && dis[*it] != discnt && val[*it] <= alw[mn])
			{
				que.push(*it);
				vstd[to] = count;
				pars[to] = *it;
			}
		}

		while(!que.empty())
		{
			temp = que.front();
			from = edge[temp].Y;
			que.pop();

			if(from == n) break;

			for(it = mp[from].begin(); it != mp[from].end(); it++)
			{
				to = edge[*it].Y;
				if(vstd[to] != count && dis[*it] != discnt && val[*it] <= alw[mn])
				{
					que.push(*it);
					vstd[to] = count;
					pars[to] = *it;
				}
			}

		}

		while(!que.empty()) que.pop();

		if(vstd[n] != count)
		{
			flag = false;
			break;
		}

		while(temp != -1)
		{
			dis[temp] = discnt;
			temp = pars[edge[temp].X];
		}

		count++;
	}
	discnt++;

	if(flag) 
	printf("%d\n", alw[mn]);
	else 
	printf("%d\n", alw[mx]);
}

int main()
{
	init();
	solve();
	return 0;
}
