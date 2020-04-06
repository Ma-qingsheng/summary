#include<stdio.h>
int main()
{
	int a=95859,b,c,d=9,st=0;
	while(st==0)
	{
		a++;
		b=(a%100-a%10)*100;
		c=a%10000-a%1000;
		if(b==c&&a%10==9)
		{
			st=1;
		}
	}
	printf("%d",a);
	return 0;
}
