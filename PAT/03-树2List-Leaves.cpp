#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct Node{
	int left;
	int right;	
};
struct Node Tree[MAXSIZE];


struct QNode{
	int front;
	int rear;
	int data[MAXSIZE];
};
typedef struct QNode* Queue;

Queue init(){
	Queue q=(Queue)malloc(sizeof(struct QNode));
	q->front=q->rear=-1;
	return q;
}

int isEmpty(Queue q){
	return (q->front==q->rear)?1:0;
} 

void AddQ(int c,Queue q){
	if((q->rear+1)%MAXSIZE==q->front){
		return;
	}else{
		q->rear=(q->rear+1)%MAXSIZE;
		q->data[q->rear]=c;
	}
}

int deleteQ(Queue q){
	if(isEmpty(q)){
		return -1;
	}else{
		q->front=(q->front+1)%MAXSIZE;
		return q->data[q->front];
	}
}




int main(){
	int N;
	scanf("%d",&N);
	int mark[N];
	for(int i=0;i<N;i++){
		mark[i]=1;
	}
	int k=0;
	char cl,cr;
	for(int i=0;i<N;i++){
				getchar();
				scanf("%c %c",&cl,&cr);
				if(cl!='-'){
					k=cl-'0';
					Tree[i].left=k;
					mark[k]=0;
				}else{
					Tree[i].left=-1;
				}
				if(cr!='-'){
					k=cr-'0';
					Tree[i].right=k;
					mark[k]=0;
			}else{
				Tree[i].right=-1;
			}
		}
	int root;
	for(int i=0;i<N;i++){
		if(mark[i]==1){
			root=i;
			break;
		}
	}
	Queue q=init();
	AddQ(root,q);
	int num=0; 
	while(!isEmpty(q)){
		num++;
		int e=deleteQ(q);
		if(Tree[e].left==-1&&Tree[e].right==-1){
			if(num!=N){
			printf("%d ",e);	
		}else{
				printf("%d",e);
		} 
	}
		if(Tree[e].left!=-1){
			AddQ(Tree[e].left,q);
		}
		if(Tree[e].right!=-1){
		AddQ(Tree[e].right,q);
		}
		
	}
	return 0;
}
