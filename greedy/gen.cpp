#include <bits/stdc++.h>


int main()
{
	printf("1\n\n5000\n");

	for(int i = 50000; i >= -50000; i--)
	{
		if(i != 0 )printf("%d %d\n", i, i);
		else printf("0 1\n");
	}
	printf("0 0\n");
}