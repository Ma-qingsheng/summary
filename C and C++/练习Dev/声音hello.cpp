#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(void)
{
	printf("hello,world\n");
	printf("接下来请欣赏bobo的声音！");
	PlaySound(".wav",NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	getch();
	
	
	return 0;
}
