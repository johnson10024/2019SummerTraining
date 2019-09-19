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

int n, k;
int cur = 0;
int temp;

char line[1000] = {0};
char *fnd, *tmp;
char pat[1000];
bool flag;

void dfs(int lvl)
{
	temp = 0;
	for(int i = 0; i <= k - 1; i++)
	{
		if(cur >= n) return;

		line[lvl] = 'A' + i;

		flag = true;
		for(int j = lvl; j >= 0; j--)
		{
			strcpy(pat, line + j);

			tmp = NULL;
			fnd = strstr(line, pat);

			while(fnd != NULL)
			{
				if(tmp != NULL)
				{
					if((int)(fnd - tmp) == lvl - j + 1)
					{
						flag = false;
						break;
					}
				}

				tmp = fnd;
				fnd = strstr(fnd + 1, pat);
			}

			if(!flag) break;
		}

		if(flag)
		{
// printf("%s\n", line);
			cur++;
			if(cur == n)
			{
				for(int j = 0; j <= lvl; j++)
				{
					if(j > 0 && j % 4 == 0 && j % 64 != 0) printf(" ");
					printf("%c", line[j]);
					if(j % 64 == 63 && j != lvl) printf("\n");
				}
				printf("\n");
				printf("%d\n", lvl + 1);

				return;
			}

			dfs(lvl + 1);
		}
	}

	line[lvl] = 0;
}

void solve()
{
	scanf("%d %d", &n, &k);

	while(n + k > 0)
	{

		cur = 0;
		memset(line, 0, sizeof(line));
		dfs(0);

		scanf("%d %d", &n, &k);
	}
}

int main()
{
	init();
	solve();
	return 0;
}