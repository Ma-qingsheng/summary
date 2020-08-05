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
		//����ѧ������
    printf("ѧ������N=");
    scanf("%d",&N);
    	//������̬�ṹ������
    stus=(Student*)malloc(sizeof(Student)*N);
	    //�����ѧ��ѧ�ţ�������ĳ�ſ�ƽʱ�����Գɼ�����Щ�ֶε�ֵ֮��ո�
	    //����),�����ɼ�����ƽʱ�����Էֱ�ռ0.2,0.8�����Զ�����
	    //������һ��ѧ���󣬻س�����������һ��ѧ����Ϣ
    inputInformation(stus,N);
    	//��ѧ���ɼ���¼�����ļ��������ļ���ر��ļ�
    saveInformation(stus,N,"data.txt");
   		 //�ͷ��ڴ�
    free(stus);
    	//���ļ��ж�ȡѧ���ɼ���¼�������͡���������ɼ���Ӧ��ѧ��������Ϣ
    printf("ȫ��ѧ����������ͺ����ѧ����Ϣ����:\n");
    outputInformation("data.txt");
    return 0;
}
