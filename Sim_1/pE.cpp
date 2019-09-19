#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void init()
{
	
}

int distance(pair<int,int>en,pair<int,int>wa){
	return (en.X-wa.X)*(en.X-wa.X)+(en.Y-wa.Y)*(en.Y-wa.Y);
}
void solve()
{	
	int i,j;
	int kill=0;
	vector<pair<int,int> >enemy;
	vector<pair<int,int> >water;
	int n,m;
	int x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		enemy.push_back({x,y});
	}
	scanf("%d",&m);
	int r[20200];
	for(i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&r[i]);
		water.push_back({x,y});
	}
	for(vector<pair<int,int> >::iterator it=enemy.begin();it!=enemy.end();it++){
		for(i=0;i<m;i++){
			if(distance(*it,water[i])<=r[i]*r[i] ){
// printf("%d %f | %d %d\n", it -> X, it -> Y, water[i].X, water[i].Y);
				kill++;
				break;
			}
		}
	}
	printf("%d\n",n-kill);
}

int main()
{
	init();
	solve();
}
