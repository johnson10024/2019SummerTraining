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

vector<int> vec;

void solve()
{
	int n;
	int temp;
	vector<int>::iterator it;

	while(scanf("%d", &n) != EOF)
	{
		vec.clear();

		for(int i = 0; i <= n - 1; i++)
		{
			scanf("%d", &temp);
			it = lower_bound(vec.begin(), vec.end(), temp);

			if(it == vec.end()) vec.push_back(temp);
			else *it = temp;
		}

		printf("%d\n", (int)vec.size());
	}
}

int main()
{
	init();
	solve();
	return 0;
}