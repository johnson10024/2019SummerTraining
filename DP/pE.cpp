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

bool comp(pii p1, pii p2)
{
	return p1.X < p2.X;
}

void init()
{
}

vector<int> vec;
vector<int> rec;
int rev[10010];
int pos[10010];

void solve()
{
	int n;
	
	int temp;
	int mx;
	vector<int>::iterator it;

	while(scanf("%d", &n) != EOF)
	{
		vec.clear();
		rec.clear();

		for(int i = 0; i <= n - 1; i++)
		{
			scanf("%d", &temp);
			vec.push_back(temp);

			it = lower_bound(rec.begin(), rec.end(), temp);
			pos[i] = (int)(it - rec.begin());
			if(it == rec.end())
			{
				rec.push_back(temp);
			}
			else *it = temp;
		}

		rec.clear();
		for(int i = n - 1; i >= 0; i--)
		{
			it = lower_bound(rec.begin(), rec.end(), vec[i]);
			rev[i] = (int)(it - rec.begin());

			if(it == rec.end()) rec.push_back(vec[i]);
			else *it = vec[i];
		}
// for(int i = 0; i <= n - 1; i++) printf("%d ", pos[i]); printf("\n"); for(int i = 0; i <= n - 1; i++) printf("%d ", rev[i]); printf("\n");
		mx = -1;
		for(int i= 0; i <= n - 1; i++)
		{
			mx = max(mx, min(pos[i], rev[i]));
		}

		printf("%d\n", mx * 2 + 1);
	}
}

int main()
{
	init();
	solve();
	return 0;
}