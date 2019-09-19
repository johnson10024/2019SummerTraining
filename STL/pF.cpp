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

priority_queue<int> pq;
queue<int> que;

void init()
{
	while(!pq.empty())
	{
		pq.pop();
	}
	while(!que.empty())
	{
		que.pop();
	}
}

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int time = 0;

	int pri[1000];
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d", &pri[i]);

		pq.push(pri[i]);
		que.push(i);
	}
	
	int cur = -1;

	while(cur != m)
	{
		while(pri[que.front()] < pq.top())
		{
			que.push(que.front());
			que.pop();
		}

		cur = que.front();
		pq.pop();
		que.pop();
		time++;
	}

	printf("%d\n", time);

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