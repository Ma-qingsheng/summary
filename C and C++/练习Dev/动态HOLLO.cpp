/*
//�Զ���������Ϊ�洢�ṹ����д���������ĺ�������㷨
#include<iostream>
#include<cstdio>  
#include<stdlib.h>  
using namespace std; 
typedef int Elemtype;  
typedef struct BiTnode {  
        Elemtype data;//������  
        struct BiTnode* Lchild,*Rchild; //����������  
}BiTnode,*BiTree;  
int create(BiTree *T) {  
	Elemtype ch;  
	Elemtype temp;  
	scanf("%d",&ch);  
	temp=getchar();  
	if(ch==-1)  {  
		*T=NULL;  
	}  
	else {  
		*T=(BiTree)malloc(sizeof(BiTnode) );  
		if(!(*T))  {  
			exit(-1);  
		}  
		else {  
			(*T)->data=ch;  
			printf("������%d����ڵ��ֵ",ch);  
			create(&(*T)->Lchild);  
			printf("������%d���ҽڵ��ֵ",ch);  
			create(&(*T)->Rchild); 
		}
	} 
return 1; 
} 
  //�������������  
void lasTraverse(BiTree T) {  
	if(T==NULL){return;}
	lasTraverse(T->Lchild);
	lasTraverse(T->Rchild); 
	printf("%d ",T->data); 
	
}
int main() {  
	BiTree T;  
	BiTree *p=(BiTree*)malloc(sizeof(BiTree));  
	printf("�������һ���ڵ��ֵ��-1����û��Ҷ�ڵ�:\n");  
	create(&T);  
	printf("���������������\n");
	lasTraverse(T);  
	printf("\n");  
	return 0;
}




�ж�pastack��ָ��ջ�Ƿ�Ϊ��ջ,��pastack��ָ��ջΪ��ջʱ,�򷵻�1,���򷵻�0
int isEmptyStack_seq( PSeqStack pastack ) {
return pastack->t == -1;
}   
//�þ���������洢��ʽ����ά���飩ʵ�־���ת���㷨��
#include <stdio.h>
void Transpose(int a[m][n])
{
    int i,j,temp;
    for(i = 0;i < n;i++)
        for(j = 0;j < m;j++)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }

    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
            printf("%d", a[i][j]);
        printf("\n");
    }    
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int A[m][n];
    Transpose(A);
    printf("\n");
    return 0;
}
//����㷨������������������ָ��P��ָ�ڵ��ǰ���ڵ��ָ��
BiThrTree InorderPre(BiThrTree p)
{
	BiThrTree q;
	if (p->ltag == -1)
		q=p->lchild 
	else{
		q=p->lchild;
		while (q->rtag==0 ) q=q->rchild;
	}
	return (q);
} */
//������Fib(n)�ĵݹ��㷨��
int Fib(int x){
    if (x <= 0){
        return 0;
    }
    if (x == 1 || x == 2){
        return 1;
    }
    return Fib(x - 2) + Fib(x - 1);
}

