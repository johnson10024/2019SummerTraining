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

bool comp(pair<string, int>  p1, pair<string, int> p2)
{
	return p1.Y < p2.Y;
}

char inp[5050];
int hap[5050] = {0};
int unh[5050] = {0};
char out[5050] = {0};
map<string, int> mp;
vector< pair<string, int> > vec;
string temp;

void solve()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%s", inp);
		temp = inp;
		mp[temp]++;
	}

	for(pair<string, int> p : mp)
	{
		vec.push_back(p);
	}

	sort(vec.begin(), vec.end(), comp);
	int sz = vec.size();
// for( pair<string, int> p : vec) printf("%s %d\n", p.X.c_str(), p.Y);
	int ones = 0;
	temp = vec[0].X;
	for(int i = sz - 1; i >= 0; i--)
	{
		ones = 0;
		for(int j = 0; j <= m - 1; j++)
		{
			if(vec[i].X[j] == '1') ones++;
		}
// printf("%d\n", ones);

		if(ones >= 8 && ones <= 15)
		{
			temp = vec[i].X;
			break;
		}
	}

	printf("%s\n", temp.c_str());

}

int main()
{
	init();
	solve();
	return 0;
}