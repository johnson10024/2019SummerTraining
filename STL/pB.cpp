#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
#include <set>
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

set<string> st;

void init()
{
}

void solve()
{
	string temp;
	char inp[500];
	int length;

	char *found;

	while(scanf("%s", inp) != EOF)
	{
		length = strlen(inp);
		for(int i = 0; i <= length - 1; i++)
		{
			inp[i] = tolower(inp[i]);
		}

		char delim[] = "~`1234567890!@#$%^&*()-_+={}[]|\\\'\":;<>?,./";
		found = strtok(inp, delim);

		while(found != NULL)
		{
			temp = found;
			st.insert(temp);

			found = strtok(NULL, delim);
		}
	}

	for(string s : st)
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