#include <bits/stdc++.h>
using namespace std;

int all[8];

void init()
{
	for(int i = 0; i < 8; i++)
	{
		all[i] = i + 1;
	}
}

int n;
int cnt = 0;
vector<int> vecs[50000];
bool used[50000] = {0};
int pos[100];
int pos1[100];

vector<int> ans[50000];
bool flag = false;


void dfs(int lvl)
{
	if(lvl == cnt)
	{
		flag = true;
		return;
	}

	if(lvl == 0)
	{

		ans[lvl] = vecs[0];
		used[0] = true;
		dfs(lvl + 1);
		if(flag) return;
		used[0] = false;

	}

	bool check;
	for(int i = 0; i <= cnt - 1; i++)
	{
		if(flag) return;
		if(used[i]) continue;
		check = true;
		
		for(int j = 0; j < n; j++)
		{
			pos[ans[lvl - 1][j]] = j;
		}

		for(int j = 0; j < n; j++)
		{
			if(abs(j - pos[vecs[i][j]]) > 1)
			{
				check = false;
				break;
			}
		}

		if(check)
		{
//printf("lvl = %d,", lvl); for(int k : vecs[i]) printf("%d ", k); printf("\n");
			ans[lvl] = vecs[i];
			used[i] = true;
			dfs(lvl + 1);
			used[i] = false;
		}
	}
}

void solve()
{
	scanf("%d", &n);


	do
	{
		for(int i = 0; i <= n - 1; i++)
		{
			vecs[cnt].push_back(all[i]);
		}
		cnt++;
	}while(next_permutation(all, all + n));

	dfs(0);

	for(int i = 0; i < cnt; i++)
	{
		for(int j = 0; j <= n - 1; j++)
		{
			if(j > 0) printf(" ");
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	init();
	solve();
}
