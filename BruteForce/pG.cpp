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

struct state
{
	int wat[3];

	bool operator==(const state &s2)
	{
		return (wat[0] == s2.wat[0]) && (wat[1] == s2.wat[1]) && (wat[2] == s2.wat[2]);
	}
};

int vol[3];
int wat[3];
int tgt;

vector<state> sts;
vector<int> steps;
state temp;
int wtemp;

int mn = -1;
int stp;
bool flag;
int sz;

void dfs(int step, state cur)
{
	sz = sts.size();
	flag = false;
	for (int i = 0; i <= sz - 1; i++)
	{
		if(sts[i] == cur)
		{
			flag = true;
			if (steps[i] < step) return;

			steps[i] = step;
		}
	}

	if(!flag)
	{
		sts.push_back(cur);
		steps.push_back(step);
	}

// printf("%d %d %d %d\n", cur.wat[0], cur.wat[1], cur.wat[2], step);

	for(int i = 0; i < 3; i++)
	{
		if(cur.wat[i] > mn && cur.wat[i] <= tgt)
		{
			mn = cur.wat[i];
			stp = step;
		}
		if(cur.wat[i] == mn)
		{
			if(step < stp) stp = step;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				continue;
			temp = cur;

			if (vol[j] - temp.wat[j] >= temp.wat[i] && temp.wat[i] > 0)
			{
				wtemp = temp.wat[i];

				temp.wat[j] = temp.wat[j] + temp.wat[i];
				temp.wat[i] = 0;

				dfs(step + wtemp, temp);
			}
			else if(vol[j] - temp.wat[j] > 0 && temp.wat[i] > 0)
			{
				wtemp = vol[j] - temp.wat[j];

				temp.wat[i] = temp.wat[i] - (vol[j] - temp.wat[j]);
				temp.wat[j] = vol[j];

				dfs(step + wtemp, temp);
			}
		}
	}
}

void init()
{
	mn = -1;
	stp = INF;
}

void solve()
{
	scanf("%d %d %d %d", &vol[0], &vol[1], &vol[2], &tgt);

	wat[0] = 0;
	wat[1] = 0;
	wat[2] = vol[2];

	temp = {{0, 0, vol[2]}};

	dfs(0, temp);
	printf("%d %d\n", stp, mn);
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