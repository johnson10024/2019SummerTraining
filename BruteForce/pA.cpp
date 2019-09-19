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

vector< pair<int, int> > num[100];

void solve()
{
	int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int divi;
	int dvnd;
	string s0, s1;

	while(next_permutation(nums, nums + 10))
	{
		divi = 0;
		dvnd = 0;

		for(int i = 0; i <= 4; i++)
		{
			divi = divi * 10 + nums[i];
		}

		for(int i = 5; i < 10; i++)
		{
			dvnd = dvnd * 10 + nums[i];
		}

		if(divi % dvnd == 0 && divi / dvnd < 100)
		{
			num[divi / dvnd].push_back({divi, dvnd});
		}
	}

	int n;
	scanf("%d", &n);

	for(int i = 0; i < 100; i++)
	{
		sort(num[i].begin(), num[i].end());
	}

	while(n > 0)
	{
		if(num[n].size() == 0) printf("There are no solutions for %d.\n", n);
		else
		{
			for(pii p : num[n])
			{
				printf("%05d / %05d = %d\n", p.X, p.Y, n);
			}
		}

		scanf("%d", &n);
		if(n != 0) printf("\n");

	}

}

int main()
{
	init();
	solve();
	return 0;
}