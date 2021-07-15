//******************************队列的顺序存储****************************/ 
#include<stdio.h>
#define MAXSIZE 1000  //队列大小设置为1000
#define Element int  

struct QNode{
	Element Data[MAXSIZE];
	int front;   //队列头下标
	int rear;   //队列尾部下标 
}; 
typedef QNode *Queue;  //定义一个QNode的指针Queue

//**入队函数 
void AddQ(Queue Q,Element item){
	if((Q->rear+1)%MAXSIZE==Q->front){  //判断队列是否满 
		printf("队列满");
		return;
	}else{
		Q->rear=(Q->rear+1)%MAXSIZE;
		Q->Data[Q->rear]=item;
	}
}

//**出队函数
Element DeleteQ(Queue Q){
	if(Q->rear==Q->front){
		printf("空");
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
