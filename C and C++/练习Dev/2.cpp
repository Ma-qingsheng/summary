//在数组中找到多少个与m相同的数 。 
#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=2;i<a;i++)
    {
    	if(a%i==0)
    	{
		printf("%d",i);
    	break;
        }
	}
	return 0;
}
