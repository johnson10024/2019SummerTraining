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


char inp[10010];
int st[30];
int all[30];
set<int> mp[100];
int pos[100];
int ans[100];

void init()
{
	memset(st, 0, sizeof(st));
	for(int i = 0; i < 100; i++)
	{
		mp[i].clear();
	}
}

void solve()
{
	scanf("%s", inp);

	char *cur;
	int root;
	int mx, mn, amn;
	int count, length;

	while(inp[0] != '#')
	{
		init();
		count = 0;
		cur = strtok(inp, ":;");

		while(cur != NULL)
		{
			length = strlen(cur);

			if(count % 2)
			{
				for(int i = 0; i <= length - 1; i++)
				{
					mp[root].insert(cur[i] - 'A');
					mp[cur[i] - 'A'].insert(root);
					st[cur[i] - 'A'] = 1;
				}
			}
			else
			{
				root = cur[0] - 'A';
				st[cur[0] - 'A'] = 1;
			}

			cur = strtok(NULL, ":;");
			count++;
		}
//for(int i = 0; i <= 7; i++) {printf("%c:", i + 'A');for(int j : mp[i])printf("%c ", 'A' + j); printf("\n");}
		count = 0;
		for(int i = 0; i <= 'Z' - 'A'; i++)
		{
			if(st[i] == 1)
			{
				all[count] = i;
				count++;
			}
		}

		amn = INF;
		do
		{
			for(int i = 0; i <= count - 1; i++)
			{
				pos[all[i]] = i;
			}

// for(int i = 0; i <= count - 1; i++) printf("%d ", all[i]); printf("\n"); for(int i = 0; i <= count - 1; i++) printf("%d ", pos[i]); printf("\n\n");

			mx = -1;
			for(int i = 0; i <= count; i++)
			{
				for(int j : mp[all[i]])
				{
					if(abs(pos[all[i]] - pos[j]) > mx)
					{
						mx = abs(pos[all[i]] - pos[j]);
					}
				}
			}

			if(mx < amn)
			{
				amn = mx;

				for(int i = 0; i <= count - 1; i++)
				{
					ans[i] = all[i];
				}
			}

		}while(next_permutation(all, all + count));
	
		for(int i = 0; i <= count - 1; i++)
		{
			printf("%c ", ans[i] + 'A');
		}
		printf("-> %d\n", amn);

		scanf("%s", inp);
	}
}

int main()
{
	init();
	solve();
	return 0;
}