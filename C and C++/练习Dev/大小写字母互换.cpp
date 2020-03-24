#include<stdio.h>
#include<string.h>
char a[500];
int main()
{
    
    int i = 0;
    while(1)
    {
        scanf("%c",&a[i]);
        if(a[i]=='\n')
        {
            break;
        }
        i = i + 1;
    }
    int chang = i+1;
	for(i=0;i<chang;i++)
	{
	if(a[i]>='a'&&a[i]<='z')
	     a[i]=a[i]-'a'+'A';
	else if(a[i]>='A'&&a[i]<='Z')
	     a[i]=a[i]+'a'-'A';
	     else;
		}
	printf("%s",a);
	return 0;
} 
