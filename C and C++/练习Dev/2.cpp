#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct student
{
    char stu_number[20];
    char stu_name[20];
    float usual_mark;
    float exam_mark;
    float overall_mark;
}Student;
void inputInformation(Student*stus,int N);
void saveInformation(Student*stus,int N,char*filename);
void outputInformation(char*filename);

///////    1900300623 马志远； 
//请在下面给出程序中所用到的自定义函数的完整定义
void cppy(Student *a,Student *b)
{
    strcpy(a->stu_number,b->stu_number);
    strcpy(a->stu_name,b->stu_name);
    a->usual_mark=b->usual_mark;
    a->exam_mark=b->exam_mark;
    a->overall_mark=b->overall_mark;
}
void showInformation(Student *s)
{
    //printf("[%s]",s->stu_number);
    printf("学号=%s,姓名=%s,平时成绩=%.2f,考试成绩=%.2f,总评成绩=%.2f",s->stu_number,s->stu_name,s->usual_mark,s->exam_mark,s->overall_mark);
}
void inputInformation(Student *stus,int N)
{
    for(int i=0;i<N;i++)
    {
        printf("学生%d的学号，姓名，平时成绩，考试成绩(空格分隔):\n",i);
        scanf("%s %s %f %f",stus[i].stu_number,stus[i].stu_name,&stus[i].usual_mark,&stus[i].exam_mark);
        stus[i].overall_mark=0.2*stus[i].usual_mark+0.8*stus[i].exam_mark;
        
    }
}
void saveInformation(Student *stus,int N,char *filename)
{
    FILE *pp=fopen(filename,"w");
    for(int i=0;i<N;i++)
    {
        fprintf(pp,"%s %s %.2f %.2f %.2f\n",stus[i].stu_number,stus[i].stu_name,stus[i].usual_mark,stus[i].exam_mark,stus[i].overall_mark);
        
    }
    fclose(pp);
}
void outputInformation(char *filename)
{
    FILE *pp=fopen(filename,"r");
    Student s,minn,maxx;
    printf("全部学生:\n");
    fscanf(pp,"%s %s %f %f %f\n",s.stu_number,s.stu_name,&s.usual_mark,&s.exam_mark,&s.overall_mark);
    showInformation(&s);
    printf("\n");
    minn=s;
    maxx=s;
    while(!feof(pp))
    {
        fscanf(pp,"%s %s %f %f %f\n",s.stu_number,s.stu_name,&s.usual_mark,&s.exam_mark,&s.overall_mark);
        showInformation(&s);
        printf("\n");
        if(s.overall_mark>maxx.overall_mark)maxx=s;
        else if(s.overall_mark<minn.overall_mark)minn=s;
    }   
    printf("最低分学生:\n");
    showInformation(&minn);
    printf("\n");
    printf("最高分学生:\n");
    showInformation(&maxx);
    fclose(pp);
}



int main()
{
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

