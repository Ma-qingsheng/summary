#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>


#define MAX 2 /*��������*/
#define price 0.05 /*ÿ��ÿ���ӷ���*/ 


	typedef struct time
	{
		int hour;
		int min;
	}Time; /*ʱ����*/
	typedef struct node
	{
		char num[10];
		Time reach;
		Time leave;
	}CarNode;/*������Ϣ���*/
	typedef struct NODE
	{
		CarNode *stack[MAX + 1];
		int top;
	}SeqStackCar;
	typedef struct car
	{
		CarNode *data;
		struct car *next;
	}QueueNode;
	typedef struct Node
	{
		QueueNode *head;
		QueueNode *rear;
	}LinkQueueCar; /*ģ��ͨ��*/
				   /*------------------------------------------------------------------------------*/
void InitStack(SeqStackCar *s) /*��ʼ��ջ*/
	{
		int i;
		s->stack[s->top] = NULL;
	}
	int InitQueue(LinkQueueCar *Q) /*��ʼ�����*/
	{
		Q->head = (QueueNode *)malloc (sizeof(QueueNode));
		if(Q->head != NULL){
			Q->head->next=NULL;
			Q->rear=Q->head;
			return (1);
		}
		else return (-1);
	return 0;
	}
void PRINT(CarNode *p, int room) /*��ӡ����������Ϣ*/
	{
		int A1,B1,C1,A2,B2;
		printf("\n �����뿪ʱ��/**:**/"); 
		scanf("%d:%d",&p->leave.hour,&p->leave.min);
		printf("\n �뿪�ĳ���Ϊ��");
		puts(p->num);
		printf("\n ����ʱ�䣺%d:%d",p->reach.hour,p->reach.min);
		printf("�뿪ʱ��Ϊ��%d:%d",p->leave.hour,p->leave.min);
		A1=p->reach.hour;
		A2=p->reach.min;
		B1=p->leave.hour;
		B2=p->leave.min;
		printf("\n Ӧ������Ϊ%2.1fԪ",(B1-A1)*60+(B2-A2)*price);
		free(p);
	}
int Arrival(SeqStackCar *Enter, LinkQueueCar *W) /*��������*/
	{
		CarNode *p; 
		QueueNode *t; 
		p=(CarNode *)malloc(sizeof(CarNode)); 
		flushall(); 
		printf("\ninput the number of the car(��:��A1234):"); 
		gets(p->num); 
		if(Enter->top<MAX) /*����δ������������*/ 
		{ 
			Enter->top++; 
			printf("\n �����ڳ�����%d λ��",Enter->top); 
			printf("\n�����뵽��ʱ��:/**:**/"); 
			scanf("%d:%d",&(p->reach.hour),&(p->reach.min)); 
			Enter->stack[Enter->top]=p; 
			return(1); 
		} 
		else /*�����������������*/ 
		{ 
			printf("\n�ó����ڱ���ȴ�!"); 
			t=(QueueNode *)malloc(sizeof(QueueNode)); 
			t->data=p; 
			t->next=NULL; 
			W->rear->next=t; 
			W->rear=t; 
			return(1); 
		} 
		return 0;
	}
void Leave(SeqStackCar *Enter, SeqStackCar *Temp, LinkQueueCar *W)/*�����뿪*/
	{
		int i, room; 
		CarNode *p,*t; 
		QueueNode *q; 
		/*�жϳ������Ƿ��г�*/ 
		if(Enter->top>0) /*�г�*/ 
		{ 
			while(1) /*�����뿪��������Ϣ*/ 
			{ 
				printf("\n�����복�ڳ�����λ��/1--%d/��",Enter->top); 
				scanf("%d",&room); 
				if(room>=1&&room<=Enter->top) break; 
			} 
			while(Enter->top>room) /*�����뿪*/ 
			{ 
				Temp->top++; 
				Temp->stack[Temp->top]=Enter->stack[Enter->top]; 
				Enter->stack[Enter->top]=NULL; 
				Enter->top--; 
			} 
			p=Enter->stack[Enter->top]; 
			Enter->stack[Enter->top]=NULL; 
			Enter->top--; 
			while(Temp->top>=1) 
			{ 
				Enter->top++; 
				Enter->stack[Enter->top]=Temp->stack[Temp->top]; 
				Temp->stack[Temp->top]=NULL; 
				Temp->top--; 
			} 
			PRINT(p,room); 
			/*�ж�ͨ�����Ƿ��г�����վ�Ƿ�����*/ 
			if((W->head!=W->rear)&&Enter->top<MAX) /*����ĳ������복��*/ 
			{ 
				q=W->head->next; 
				t=q->data; 
				Enter->top++; 
				printf("\n�����%s�ų����복����%dλ��.",t->num,Enter->top); 
				printf("\n���������ڵ�ʱ��/**:**/:"); 
				scanf("%d:%d",&(t->reach.hour),&(t->reach.min)); 
				W->head->next=q->next; 
				if(q==W->rear) W->rear=W->head; 
				Enter->stack[Enter->top]=t; 
				free(q); 
			} 
			else printf("\n�����û�г�.\n"); 
		} 
		else printf("\n������û�г�."); /*û��*/ 
	}
void List1(SeqStackCar *S) /*�б���ʾ������Ϣ*/
	{
		int i; 
		if(S->top>0) /*�жϳ�վ���Ƿ��г�*/ 
		{ 
			printf("\n����:"); 
			printf("\n λ�� ����ʱ�� ���ƺ�\n"); 
			for(i=1;i<=S->top;i++) 
			{ 
				printf(" %d ",i); 
				printf("%d:%d ",S->stack[i]->reach.hour,S->stack[i]->reach.min); 
				puts(S->stack[i]->num); 
			} 
		} 
		else printf("\n������û�г�"); 
	}
void List2(LinkQueueCar *W) /*�б���ʾ�����Ϣ*/
	{
		QueueNode *p; 
		p=W->head->next; 
		if(W->head!=W->rear) /*�ж�ͨ�����Ƿ��г�*/ 
		{ 
			printf("\n�ȴ������ĺ���Ϊ:"); 
			while(p!=NULL) 
			{ 
				puts(p->data->num); 
				p=p->next; 
			} 
		} 
		else printf("\n�����û�г�."); 
	}
void List(SeqStackCar S, LinkQueueCar W)/*��ʾ�泵��Ϣ*/
	{
		int flag,tag; 
		flag=1; 
		while(flag) 
		{ 
			printf("\n��ѡ�� 1|2|3:"); 
			printf("\n1.����\n2.���\n3.����\n"); 
			while(1) 
			{ 
				scanf("%d",&tag); 
				if(tag>=1||tag<=3) break; 
				else printf("\n��ѡ�� 1|2|3:"); 
			}
			switch(tag) 
			{ 
				case 1:List1(&S);break; /*�б���ʾ������Ϣ*/ 
				case 2:List2(&W);break; /*�б���ʾ�����Ϣ*/ 
				case 3:flag=0;break; 
				default: break; 
			}
		}
	}
void menu()
	{
		printf("\t*************��ӭʹ�á��þò�����ͣ������ϵͳ*************\n");
		printf("\t*                                                        *\n");
		printf("\t*                                                        *\n");
		printf("\t*                        1.��������                      *\n");
		printf("\t*                        2.�����뿪                      *\n");
		printf("\t*                        3.�б���ʾ                      *\n");
		printf("\t*                        0.�˳�ϵͳ                      *\n");
		printf("\t*                                                        *\n");
		printf("\t*                               ��Ϣ��ѧ�뼼��           *\n");
		printf("\t*                                                        *\n");
		printf("\t*                                                        *\n");
		printf("\t*************��ӭʹ�á��þò�����ͣ������ϵͳ*************\n");
	}
	/*------------------------------------------------------------------------------*/
int main()
{
	SeqStackCar Enter, Temp;
	LinkQueueCar Wait;
	int ch;
	InitStack(&Enter); /*��ʼ����վ*/
	InitStack(&Temp); /*��ʼ����·����ʱջ*/
	InitQueue(&Wait); /*��ʼ��ͨ��*/
	do
	{
		menu();
		switch (ch)
		{
		case 1:
			Arrival(&Enter, &Wait);
			break; /*��������*/
		case 2:
			Leave(&Enter, &Temp, &Wait);
			break; /*�����뿪*/
		case 3:
			List(Enter, Wait);
			break; /*��ӡ�б���Ϣ*/
		case 0:
			printf("лл����ʹ�ã��ټ���\n");
			exit(0);
			break;/*�˳�������*/
		default:
			printf("���������������������ѡ���Ӧ������\n");
		}
	} while (1);
	return 0;
}
