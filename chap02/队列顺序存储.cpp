//******************************���е�˳��洢****************************/ 
#include<stdio.h>
#define MAXSIZE 1000  //���д�С����Ϊ1000
#define Element int  

struct QNode{
	Element Data[MAXSIZE];
	int front;   //����ͷ�±�
	int rear;   //����β���±� 
}; 
typedef QNode *Queue;  //����һ��QNode��ָ��Queue

//**��Ӻ��� 
void AddQ(Queue Q,Element item){
	if((Q->rear+1)%MAXSIZE==Q->front){  //�ж϶����Ƿ��� 
		printf("������");
		return;
	}else{
		Q->rear=(Q->rear+1)%MAXSIZE;
		Q->Data[Q->rear]=item;
	}
}

//**���Ӻ���
Element DeleteQ(Queue Q){
	if(Q->rear==Q->front){
		printf("��");
		return -1;
	}else{
		Q->front=(Q->front+1)%MAXSIZE;
		Element e=Q->Data[Q->front];
		return e;
	}
}

int main(){
	return 0;
} 
