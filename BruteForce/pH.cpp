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

map<int, int> state;

int mnb = INF;
int mnw = INF;
int temp;

void dfs(int s, int step)
{
printf("%04x", s);
	if(state.find(s) != state.end() && step >= state[s])
	{
printf("r\n");
		return;
	}
printf("\n");
	state[s] = step;

	if(s == 0xffff)
	{
		mnb = step;
		return;
	}
	if(s == 0)
	{
		mnw = step;
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			temp = s;
			
			temp ^= 1 << (4 * i + j);
			if(j > 0) temp ^= (1 << (4 * i + j - 1));
			if(j < 3) temp ^= (1 << (4 * i + j + 1));
			if(i > 0) temp ^= (1 << (4 * (i - 1) + j));
			if(i < 3) temp ^= (1 << (4 * (i + 1) + j));
printf("%d %d: ", i, j);
			dfs(temp, step + 1);
		}
	}
}

void init()
{
}

void solve()
{
	char inp[10];
	int s0 = 0;
	for(int i = 0; i < 4; i++)
	{
		scanf("%s", inp);
		for(int j = 0; j < 4; j++)
		{
			s0 <<= 1;
			if(inp[j] == 'b') s0 |= 1;
		}
	}
	
	dfs(s0, 0);

	printf("%d\n", min(mnb, mnw));
}

int main()
{
	init();
	solve();
	return 0;
}