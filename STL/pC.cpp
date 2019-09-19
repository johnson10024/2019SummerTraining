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

void solve()
{
	char inp[1000];

	scanf("%s", inp);

	map<char, int> st;
	vector< map<char, int> > vec;
	vector<string> strs;

	int length;

	while(inp[0] != '#')
	{
		st.clear();
		length = strlen(inp);

		strs.push_back(inp);

		for(int i = 0; i <= length - 1; i++)
		{
			st[tolower(inp[i])]++;
		}

		vec.push_back(st);
		scanf("%s", inp);
	}
	
	length = vec.size();
	
	vector<string> ans;
	bool flag = false;
	for(int i = 0; i <= length - 1; i++)
	{
		flag = false;
		for(int j = 0; j <= length - 1; j++)
		{
			if(i == j) continue;

			if(vec[i] == vec[j])
			{
				flag = true;
				break;
			}
		}

		if(!flag) ans.push_back(strs[i]);
	}

	sort(ans.begin(), ans.end());
	for(string s : ans)
	{
		printf("%s\n", s.c_str());
	}

}

int main()
{
	init();
	solve();
	return 0;
}