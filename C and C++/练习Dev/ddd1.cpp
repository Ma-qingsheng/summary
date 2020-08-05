#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
	typedef struct student{
	    char stu_number[20];
	    char stu_name[20];
	    float usual_mark;
	    float exam_mark;
	    float overall_mark;
	}Student;
	Student * stus,* p,* next,* head;
    int N,i=0;
		//输入学生人数
    printf("学生人数N=");
    scanf("%d",&N);
    	//创建动态结构体数组
    p=stus=(Student*)malloc(sizeof(Student)*N);
	
	
	while(i < N){
		if(i == 0) head=stus;
		scanf("%s %s %f %f",stus->stu_number,stus->stu_name,&stus->usual_mark,&stus->exam_mark);
		stus->overall_mark = 0.2*stus->usual_mark + 0.8*stus->exam_mark;
		i++;
	}
	printf("%s %s %f %f",head->stu_number,head->stu_name,head->usual_mark,head->exam_mark);
	return 0;
}
