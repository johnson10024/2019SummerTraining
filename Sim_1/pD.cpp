#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int work[104000];
void init()
{

}

void solve()
{
	int i,j,tmp;
	int n,k;
	int sev;
	int mx=0;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		for(j=0;j<1000;j++){
			work[tmp+j]++;
		}
	}
	for(i=0;i<104000;i++){
		if(work[i]>mx){
			mx=work[i];
		}
	}
	if(mx%k!=0){
		sev=mx/k+1;
	}
	else{
		sev=mx/k;
	}
	printf("%d\n",sev);
}

int main()
{
	init();
	solve();
}
