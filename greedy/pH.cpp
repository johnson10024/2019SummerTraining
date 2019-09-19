#include <algorithm>
#include <cstdio>
#include <iostream>
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

vector<int> vec;
vector<int> ans;
int ppl[4];

void init()
{
	vec.clear();
	ans.clear();
}

void solve()
{
	int n;
	scanf("%d", &n);

	int temp;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	int time = 0;

	int count = vec.size();
	while(count > 3)
	{
		if(vec[0] + vec[count - 2] < 2 * vec[1])
		{
			time += 2 * vec[0] + vec[count - 2] + vec[count - 1];

			ans.push_back(vec[0]);
			ans.push_back(vec[count - 2]);
			ans.push_back(-1);

			ans.push_back(vec[0]);
			ans.push_back(-1);

			ans.push_back(vec[0]);
			ans.push_back(vec[count - 1]);
			ans.push_back(-1);

			ans.push_back(vec[0]);
			ans.push_back(-1);
		}
		else
		{
			time += vec[0] + 2 * vec[1] + vec[count - 1];

			ans.push_back(vec[0]);
			ans.push_back(vec[1]);
			ans.push_back(-1);

			ans.push_back(vec[0]);
			ans.push_back(-1);

			ans.push_back(vec[count - 2]);
			ans.push_back(vec[count - 1]);
			ans.push_back(-1);

			ans.push_back(vec[1]);
			ans.push_back(-1);
		}

		count -= 2;
		vec.pop_back();
		vec.pop_back();
	}

	if(count == 3)
	{
		time += vec[0] + vec[1] + vec[2];

		ans.push_back(vec[0]);
		ans.push_back(vec[1]);
		ans.push_back(-1);

		ans.push_back(vec[0]);
		ans.push_back(-1);

		ans.push_back(vec[0]);
		ans.push_back(vec[2]);
		ans.push_back(-1);
	}
	else if(count == 2)
	{
		time += vec[1];

		ans.push_back(vec[0]);
		ans.push_back(vec[1]);
		ans.push_back(-1);
	}
	else if(count == 1)
	{
		time += vec[0];

		ans.push_back(vec[0]);
		ans.push_back(-1);
	}

	printf("%d\n", time);
	int length = ans.size();
	for(int i = 0; i <= length - 1; i++)
	{
		if(i > 0 && ans[i] != -1 && ans[i - 1] != -1) printf(" ");
		if(ans[i] != -1) printf("%d", ans[i]);
		else printf("\n");
	}

}

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		init();
		solve();
		if(n > 0) printf("\n");
	}

	return 0;
}