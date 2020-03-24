#include<stdio.h>
#include<cmath>
int main()
{
	int n,now=1,num=2;
	scanf("%d",&n);
	while(now<=n)
	{
		int a=0;
		for(int i=2;i<=sqrt(num);i++)
		{
			if(num%i==0)
			{a=1;
			break;}
		}
		if(a==0)
		printf("%d ",now);
		now++;
		num++;
	 }	
	 return 0; 
}



