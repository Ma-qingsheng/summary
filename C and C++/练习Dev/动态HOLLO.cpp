/*
//以二叉链表作为存储结构，请写出二叉树的后序遍历算法
#include<iostream>
#include<cstdio>  
#include<stdlib.h>  
using namespace std; 
typedef int Elemtype;  
typedef struct BiTnode {  
        Elemtype data;//数据域  
        struct BiTnode* Lchild,*Rchild; //左右子树域；  
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
			printf("请输入%d的左节点的值",ch);  
			create(&(*T)->Lchild);  
			printf("请输入%d的右节点的值",ch);  
			create(&(*T)->Rchild); 
		}
	} 
return 1; 
} 
  //后序遍历二叉树  
void lasTraverse(BiTree T) {  
	if(T==NULL){return;}
	lasTraverse(T->Lchild);
	lasTraverse(T->Rchild); 
	printf("%d ",T->data); 
	
}
int main() {  
	BiTree T;  
	BiTree *p=(BiTree*)malloc(sizeof(BiTree));  
	printf("请输入第一个节点的值，-1代表没有叶节点:\n");  
	create(&T);  
	printf("后序遍历二叉树：\n");
	lasTraverse(T);  
	printf("\n");  
	return 0;
}




判断pastack所指的栈是否为空栈,当pastack所指的栈为空栈时,则返回1,否则返回0
int isEmptyStack_seq( PSeqStack pastack ) {
return pastack->t == -1;
}   
//用矩阵的正常存储方式（二维数组）实现矩阵转置算法。
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
//设计算法求中序线索二叉树中指针P所指节点的前驱节点的指针
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
//给出求Fib(n)的递归算法。
int Fib(int x){
    if (x <= 0){
        return 0;
    }
    if (x == 1 || x == 2){
        return 1;
    }
    return Fib(x - 2) + Fib(x - 1);
}

