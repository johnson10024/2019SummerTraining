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

int curs[100];
vector<int> pile[100];

void init()
{
	for(int i = 0; i < 25; i++)
	{
		curs[i] = i;
		pile[i].push_back(i);
	}
}

void solve()
{
	int n;
	scanf("%d", &n);

	int a, b;
	char op0[100], op1[100];
	int cur, curb;
	vector<int>::iterator it;

	scanf("%s", op0);

	while(strcmp(op0, "quit"))
	{
		scanf("%d %s %d", &a, op1, &b);
		cur = curs[a];
		curb = curs[b];

		if(a == b || cur == curb)
		{
			scanf("%s", op0);
			continue;
		}
		
		if(strcmp(op0, "move") == 0)
		{
			if(strcmp(op1, "onto") == 0)
			{
				for(it = pile[cur].begin(); it != pile[cur].end(); it++)
				{
					if(*it == a)
					{
						it++;
						while(it != pile[cur].end())
						{
							pile[*it].push_back(*it);
							curs[*it] = *it;
							it = pile[cur].erase(it);
						}
						break;
					}
				}

				for(it = pile[curb].begin(); it != pile[curb].end(); it++)
				{
					if(*it == b)
					{
						it++;
						while(it != pile[curb].end())
						{
							pile[*it].push_back(*it);
							curs[*it] = *it;
							it = pile[curb].erase(it);
						}
						break;
					}
				}
				
				pile[cur].pop_back();
				pile[curb].push_back(a);
				curs[a] = curs[b];
			}
			else
			{
				
				for(it = pile[cur].begin(); it != pile[cur].end(); it++)
				{
					if(*it == a)
					{
						it++;
						while(it != pile[cur].end())
						{
							pile[*it].push_back(*it);
							curs[*it] = *it;
							it = pile[cur].erase(it);
						}
						break;
					}
				}

				pile[cur].pop_back();
				pile[curb].push_back(a);
				curs[a] = curb;
			}
		}
		else
		{
			if(strcmp(op1, "onto") == 0)
			{
				for(it = pile[curb].begin(); it != pile[curb].end(); it++)
				{
					if(*it == b)
					{
						it++;
						while(it != pile[curb].end())
						{
							pile[*it].push_back(*it);
							curs[*it] = *it;
							it = pile[curb].erase(it);
						}
						break;
					}
				}

				for(it = pile[cur].begin(); it != pile[cur].end(); it++)
				{
					if(*it == a)
					{
						while(it != pile[cur].end())
						{
							pile[curb].push_back(*it);
							curs[*it] = curb;
							it = pile[cur].erase(it);
						}
						break;
					}
				}
				
			}
			else
			{
				for(it = pile[cur].begin(); it != pile[cur].end(); it++)
				{
					if(*it == a)
					{
						while(it != pile[cur].end())
						{
							pile[curb].push_back(*it);
							curs[*it] = curb;
							it = pile[cur].erase(it);
						}
						break;
					}
				}
			}
		}

// for (int i = 0; i <= n - 1; i++){printf("%d: ", i);for (it = pile[i].begin(); it != pile[i].end(); it++){if (it != pile[i].begin())printf(" ");printf("%d", *it);}printf("\n");}
// for(int i = 0; i <= n - 1; i++) printf("%d ", i); printf("\n"); for(int i = 0; i <= n - 1; i++) printf("%d ", curs[i]); printf("\n\n");

		scanf("%s", op0);
	}

	for(int i = 0; i <= n - 1; i++)
	{
		printf("%d:", i);
		for(it = pile[i].begin(); it != pile[i].end(); it++)
		{
			printf(" %d", *it);
		}
		//if(i != n - 1)
			printf("\n");
	}
}

int main()
{
	init();
	solve();
	return 0;
}