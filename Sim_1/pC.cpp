#include <bits/stdc++.h>

void init()
{

}

void solve()
{
	char input[1000]={"\0"};
	int i;
	int cnt=0;
	scanf("%s",input);
	for(i=0;i<strlen(input);i+=3){
		if(input[i]!='P'){
			cnt++;
		}
	}
	for(i=1;i<strlen(input);i+=3){
		if(input[i]!='E'){
			cnt++;
		}
	}
	for(i=2;i<strlen(input);i+=3){
		if(input[i]!='R'){
			cnt++;
		}
	}
	printf("%d\n",cnt);
}

int main()
{
	init();
	solve();
}
