#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(void)
{
	printf("hello,world\n");
	printf("������������bobo��������");
	PlaySound(".wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	getch();
	
	
	return 0;
}
