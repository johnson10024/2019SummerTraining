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

int aw[300][300];
int ct[300][300];
int mxf;

class maxFlow
{
	int *vstd;
	int *par;
	set<int> *mp;
	int vs;
	queue<int> que;
	bool flag;
	int s, e;
	int count;

public:
	int ans;
	int **cap;
	maxFlow(){};
	maxFlow(int n, int start, int end) //Numbers of node, start, end
	{
		vs = n;
		s = start;
		e = end;
		count = 1;
		flag = true;
		vstd = new int[n + 10];
		par = new int[n + 10];
		mp = new set<int>[n + 10];
		cap = new int *[n + 10];
		memset(vstd, 0, sizeof(int) * (n + 10));
		for (int i = 0; i < n + 10; i++)
		{
			cap[i] = new int[n + 10];
			memset(cap[i], 0, sizeof(int) * (n + 10));
		}
	}

	void addEdge(int from, int to, int cp)
	{
		mp[from].insert(to);
		mp[to].insert(from);

		cap[from][to] += cp;
	}

	int exe()
	{
		
		int temp;
		int mn;
		flag = true;
		ans = 0;
		while (flag)
		{
			flag = false;

			que.push(s);
			vstd[s] = count;
			par[s] = -1;

			while (!que.empty())
			{
				temp = que.front();
				que.pop();

				if (flag)
					continue;

				if (temp == e)
				{
					flag = true;
					mn = INF;

					while (par[temp] != -1)
					{
						if (cap[par[temp]][temp] < mn)
							mn = cap[par[temp]][temp];
						temp = par[temp];
					}

					ans ++;
					temp = e;
					while (par[temp] != -1)
					{
						cap[par[temp]][temp] -= mn;
						cap[temp][par[temp]] += mn;

						temp = par[temp];
					}

					continue;
				}

				for (set<int>::iterator v = mp[temp].begin(); v != mp[temp].end(); v++)
				{
					if (vstd[*v] != count && cap[temp][*v] > 0 && aw[temp][*v] <= mxf)
					{
						vstd[*v] = count;
						que.push(*v);
						par[*v] = temp;
					}
				}
			}

			count++;
		}

		return ans;
	}
};

set<int> als;
vector<int> ls;

void init()
{
}

void solve()
{
	int es, vs, t;
	scanf("%d %d %d", &vs, &es, &t);

	maxFlow mf(300, 1, vs);

	int from, to, w;
	for(int i = 0; i <= es - 1; i++)
	{
		scanf("%d %d %d", &from, &to, &w);
		
		mf.addEdge(from, to, 1);
		mf.addEdge(to, from, 1);
		aw[from][to] = w;
		aw[to][from] = w;

		als.insert(w);
	}
	
	for(set<int>::iterator it = als.begin(); it != als.end(); it++)
	{
		ls.push_back(*it);
	}

	for(int i = 1; i <= vs; i++)
	{
		for(int j = 1; j <= vs; j++)
		{
			ct[i][j] = mf.cap[i][j];
		}
	}
// for(int i = 1; i <= vs; i++) for(int j = 1; j <= vs; j++) printf("%d ", mf.cap[i][j]); printf("\n");
// for(int i = 1; i <= vs; i++) for(int j = 1; j <= vs; j++) printf("%d ", ct[i][j]); printf("\n");

	int mx = ls.size() - 1, mn = 0;
	int mid = (mx + mn) / 2;

	bool flag;
	queue<int> que;

	while(mx - mn > 1)
	{
		for(int i = 1; i <= vs; i++) for(int j = 1; j <= vs; j++) mf.cap[i][j] = ct[i][j];
		mxf = ls[mid];
		
		if(mf.exe() >= t) mx = mid;
		else mn = mid;

		mid = (mx + mn) / 2; 
	}

	for(int i = 1; i <= vs; i++) for(int j = 1; j <= vs; j++) mf.cap[i][j] = ct[i][j];
	mxf = ls[mn];
// printf("%d-%d\n", ls[mx], mf.exe());

	if(mf.exe() >= t) 
		printf("%d\n", ls[mn]);
	else 
		printf("%d\n", ls[mx]);

}

int main()
{
	init();
	solve();
	return 0;
}