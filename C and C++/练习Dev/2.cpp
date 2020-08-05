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

///////    1900300623 ��־Զ�� 
//��������������������õ����Զ��庯������������
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
    printf("ѧ��=%s,����=%s,ƽʱ�ɼ�=%.2f,���Գɼ�=%.2f,�����ɼ�=%.2f",s->stu_number,s->stu_name,s->usual_mark,s->exam_mark,s->overall_mark);
}
void inputInformation(Student *stus,int N)
{
    for(int i=0;i<N;i++)
    {
        printf("ѧ��%d��ѧ�ţ�������ƽʱ�ɼ������Գɼ�(�ո�ָ�):\n",i);
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
    printf("ȫ��ѧ��:\n");
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
    printf("��ͷ�ѧ��:\n");
    showInformation(&minn);
    printf("\n");
    printf("��߷�ѧ��:\n");
    showInformation(&maxx);
    fclose(pp);
}



int main()
{
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

