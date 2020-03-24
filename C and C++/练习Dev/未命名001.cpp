#include<stdio.h>
int main(){
	int n, ok=1;
	scanf("%d",&n);
	printf("1\n");
	for(int i=2;i<n;i++)
	 {
	   if(n%i==0)
		{
			ok=0;
			printf("%d \n",i) ;
		}
		
	 }
	if(ok==1)
	{
		printf("%d 为质数",n); 
	}
	else if(ok==0)
	{
		printf("%d不为质数",n);
	}
	
	
	
	
	return 0;
} 
