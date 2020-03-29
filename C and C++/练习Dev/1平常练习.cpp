#include<stdio.h>
int main()
{
	double a,c,d;
	char b;
	printf("%lf%c%lf",&a,&b,&c);
	if(c==0) printf("除数不能为零");
	switch(b)
	 {
		case 43:
			d=a+c;
			break;
		case 45:
			d=a-c;
			break;
		case 47:
			d=a/c;
			break;
		case 42:
			d=a*c;
			break;
		default: 
			printf("运算符号有误");
			break;
	 }
	printf("%lf",d);
	return 0;
}
