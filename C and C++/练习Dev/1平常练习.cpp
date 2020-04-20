#include <stdio.h>
int main()
{
    char S[100],T[20];
    char ch1,ch2;
    printf("Ö÷×Ö·û´®:\n");
    ch1=getchar();
    int i=0;
    while(ch1!='\n')
    {
        S[i]=ch1;
        i++;
        ch1=getchar();
    }
    printf("ÒªÉ¸Ñ¡µÄ×Ö·û´®:\n");
    ch2=getchar();
    int j=0;
    while(ch2!='\n')
    {
        T[j]=ch2;
        j++;
        ch2=getchar();
    }
  
    int m,n;
    m=0;
    n=0;
    int num=0;
    while(m<=i&&n<=j)
    {
        if(S[m]==T[n])
        {
            m++;
            n++;
        }
        else
        {
            m=m-n+1;
            n=0;
        }
        if(n==j)
        {
            num++;
            printf("p=%d\n",m-n+1);
        }
    }
    if(m==i+1)
        {
            printf("%d",num);
        }
    return 0;
}


