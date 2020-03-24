#include<stdio.h>
int main ()
{
	char sex,sports,diet,temp=' '; 
	float faHeight,moHeight;
	float Height;
	scanf("%f%f%c%c%c%c%c%c",&faHeight,&moHeight,&temp,&sex,&temp,&sports,&temp,&diet);
	if(sex=='F') Height=(faHeight+moHeight)*0.54;
	else Height=(faHeight*0.923+moHeight)/2;

	if(sports=='Y') Height = Height+0.02*Height;
	if(diet=='Y') Height = Height+0.015*Height;
	printf("%.2f",Height);
	return 0;
}
