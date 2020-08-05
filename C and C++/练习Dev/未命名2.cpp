#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
typedef struct student
{
    char stu_number[20];
    char stu_name[20];
    float usual_mark;
    float exam_mark;
    float overall_mark;
}Student;
void inputInformation(Student *stus , int N);
void saveInformation(Student *stus , int N , char*filename);
void outputInformation(char *filename);
#endif

void inputInformation(Student *stus , int N){
	int i=0;
	strust Student *p;
	p=(Student*)malloc(sizeof(Student));
	while(i < N){
		scanf("%s %s %f %f",stus->stu_number,stus->stu_name,&stus->usual_mark,&stus->exam_mark);
		stus->overall_mark = 0.2*stus->usual_mark + 0.8*stus->exam_mark;	
		i++;
	}
	
}


void saveInformation(Student *stus , int N , char*filename){
	
}


void outputInformation(char *filename){
	
}

int main(){
    Student* stus;
    int N;
		//输入学生人数
    printf("学生人数N=");
    scanf("%d",&N);
    	//创建动态结构体数组
    stus=(Student*)malloc(sizeof(Student)*N);
	    //输入各学生学号，姓名，某门课平时、考试成绩（这些字段的值之间空格
	    //隔开),总评成绩根据平时、考试分别占0.2,0.8比例自动计算
	    //输入完一个学生后，回车即可输入下一个学生信息
    inputInformation(stus,N);
    	//把学生成绩记录存入文件，存入文件后关闭文件
    saveInformation(stus,N,"data.txt");
   		 //释放内存
    free(stus);
    	//从文件中读取学生成绩记录，输出最低、最高总评成绩对应的学生完整信息
    printf("全部学生、总评最低和最高学生信息如下:\n");
    outputInformation("data.txt");
    return 0;
}
