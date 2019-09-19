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

int temp[2][2];
int cur[2][2];
int t[2][2];

void init()
{
}

void solve()
{
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);

	while(a + b + n > 0)
	{
		cur[0][0] = 1;
		cur[0][1] = 0;
		cur[1][0] = 0;
		cur[1][1] = 1;
		t[0][0] = 0;
		t[0][1] = 1;
		t[1][0] = b;
		t[1][1] = a;

		n--;

		while(n > 0)
		{
			if(n & 1)
			{
				//cur *= t
				temp[0][0] = (cur[0][0] * t[0][0] + cur[0][1] * t[1][0]) % 7;
				temp[0][1] = (cur[0][0] * t[0][1] + cur[0][1] * t[1][1]) % 7;
				temp[1][0] = (cur[1][0] * t[0][0] + cur[1][1] * t[1][0]) % 7;
				temp[1][1] = (cur[1][0] * t[0][1] + cur[1][1] * t[1][1]) % 7;

				cur[0][0] = temp[0][0];
				cur[0][1] = temp[0][1];
				cur[1][0] = temp[1][0];
				cur[1][1] = temp[1][1];
			}

			//t = t ^ 2;
			temp[0][0] = (t[0][0] * t[0][0] + t[0][1] * t[1][0]) % 7;
			temp[0][1] = (t[0][0] * t[0][1] + t[0][1] * t[1][1]) % 7;
			temp[1][0] = (t[1][0] * t[0][0] + t[1][1] * t[1][0]) % 7;
			temp[1][1] = (t[1][0] * t[0][1] + t[1][1] * t[1][1]) % 7;
			
			t[0][0] = temp[0][0];
			t[0][1] = temp[0][1];
			t[1][0] = temp[1][0];
			t[1][1] = temp[1][1];

			n >>= 1;
		}
		
		printf("%d\n", (cur[0][0] + cur[0][1]) % 7);


		scanf("%d %d %d", &a, &b, &n);
	}

}

int main()
{
	init();
	solve();
	return 0;
}