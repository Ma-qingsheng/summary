//���������ҵ����ٸ���m��ͬ���� �� 
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
