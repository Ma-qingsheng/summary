#include<stdio.h>
int main()
{
	int  a,n,a1,a2,a3,num[100],b[20];
	a1=1,a2=1;
	for(int i=3;i<=100;i++)
	{
     	a1=a2;
		a2=a3;
		a3=a1+a2;
		num[i]=a3;
	    }
	num[1]=1;num[2]=1;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&b[i]);
		}	
	for(int i=1;i<=a;i++)
	printf("%d\n",num[b[i]]);
    return 0;
}
