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
	int n, k;
	scanf("%d %d", &n, &k);

	int temp;
	for(int i = 0; i <= n - 1; i++)
	{
		scanf("%d", &temp);
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	double dist = -1;
	for(int i = 1; i <= n - 1; i++)
	{
		if((double)vec[i] - vec[i - 1] > dist) dist = vec[i] - vec[i - 1];
	}


	double far = dist / 2;
	if(k - vec[n - 1] > far) far = k - vec[n - 1];
	if(vec[0] > far) far = vec[0];

	printf("%10f\n", far);

}

int main()
{
	init();
	solve();
	return 0;
}