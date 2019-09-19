#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define INF (0x3f3f3f3f)
#define MOD (998244353)
#define PREC (0.0000001)
// #define DEBUG

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

void init()
{
}

char inp[100010];
char op[100010];
char nev[100010];

void solve()
{
	string cur = "http://www.acm.org/";
	stack<string> bk;
	stack<string> fr;

	scanf("%s", inp);

	while(strcmp(inp, "QUIT"))
	{
		if(strcmp(inp, "BACK") == 0)
		{
			if(cur.length() == 0 || bk.empty())
			{
				printf("Ignored\n");

				scanf("%s", inp);
				continue;
			}
			else
			{
				fr.push(cur);
				cur = bk.top();
				bk.pop();
			}
		}

		if(strcmp(inp, "FORWARD") == 0)
		{
			if(cur.length() == 0 || fr.empty())
			{
				printf("Ignored\n");
				
				scanf("%s", inp);
				continue;
			}
			else
			{
				bk.push(cur);
				cur = fr.top();
				fr.pop();
			}
		}

		if(strcmp(inp, "VISIT") == 0)
		{
			scanf("%s", nev);

			if(cur.length() > 0) bk.push(cur);

			cur = nev;
			while(!fr.empty())
			{
				fr.pop();
			}
		}

		printf("%s\n", cur.c_str());

		scanf("%s", inp);
	}
}

int main()
{
	init();
	solve();
	return 0;
}