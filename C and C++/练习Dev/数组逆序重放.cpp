#include<stdio.h>
#include<cmath>
int main()
{
	int n,num[100];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	    scanf("%d",&num[i]);
	} 
	for(int i=n;i>=1;i--)
	printf("%d ",num[i]);
	return 0;
 } 
