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

int pos[4];

int srt(string s)
{
	int length = s.length();
	int mea = 0;

	for(int i = 0; i <= length - 1; i++)
	{
		for(int j = i + 1; j <= length - 1; j++)
		{
			if(s[i] > s[j]) mea++;
		}
	}

	return mea;
}

bool comp(string s1, string s2)
{
	return srt(s1) < srt(s2);
}

void solve()
{
	int length, n;
	scanf("%d %d", &length, &n);

	char temp[10010];

	vector<string> vec;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%s", temp);
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), comp);

	for(int i = 0; i <= n - 1; i++)
	{
		printf("%s\n", vec[i].c_str());
	}

}

int main()
{
	init();
	solve();
	return 0;
}