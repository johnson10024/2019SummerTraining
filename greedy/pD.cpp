/*
   __  __     _                ___                         
  / / / /____(_)___  ____ _   /   |  ______________ ___  __
 / / / / ___/ / __ \/ __ `/  / /| | / ___/ ___/ __ `/ / / /
/ /_/ (__  ) / / / / /_/ /  / ___ |/ /  / /  / /_/ / /_/ / 
\____/____/_/_/ /_/\__, /  /_/  |_/_/  /_/   \__,_/\__, /  
                  /____/                          /____/   
*/

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

int plat[7][7];
int szs[7];

void init()
{
	memset(plat, 0, sizeof(plat));
}

void solve()
{
	int sum = 0;
	for(int i = 1; i <= 6; i++)
	{
		scanf("%d", &szs[i]);
		sum += szs[i];
	}

	int ans = 0;
	bool flag;

	while(sum > 0)
	{
		while(sum > 0)
		{
			ans++;
			for(int i = 0; i < 6; i++)
			{
				for(int j = 0; j < 6; j++)	//1-Check where can be started
				{
					if(plat[i][j] == 1) continue;

					for(int k = 6; k >= 1; k--)		//2-Check for fitting size
					{
						if(szs[k] <= 0) continue;
						if(i + k - 1 >= 6 || j + k - 1 >= 6) continue;

						flag = true;
						for(int l = 0; l <= k - 1; l++)		//3- Check if size k fits
						{
							for(int r = 0 ; r <= k - 1; r++)
							{
								if(plat[i + l][j + r] == 1)
								{
									flag = false;
									break;
								}
							}
							if(!flag) break;
						}

						if(flag)		//4-Mark the plate and refresh state
						{
							for(int l = 0; l <= k - 1; l++)
							{
								for(int r = 0; r <= k - 1; r++)
								{
									plat[i + l][j + r] = 1;
								}
							}

// for(int s = 0; s < 6; s++){for(int t = 0; t < 6; t++)printf("%d", plat[s][t]);printf("\n");}printf("\n");

							szs[k]--;
							sum--;
						}
					}
				}
			}

			memset(plat, 0, sizeof(plat));

		}

		printf("%d\n", ans);

		ans = 0;
		sum = 0;
		for(int i = 1; i <= 6; i++)
		{
			scanf("%d", &szs[i]);
			sum += szs[i];
		}
	}

}

int main()
{
	init();
	solve();
	// printf("\n");
	return 0;
}