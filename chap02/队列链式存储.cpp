#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define ElementType int


typedef struct TreeNode* List;
struct TreeNode{
	ElementType Data;
	List next;
};
struct QNode{
	List front;//Í·Ö¸Õë 
	List rear;//Î²Ö¸Õë	
};
typedef QNode *Queue;

Queue init(){
	Queue q=(Queue)malloc(sizeof(struct QNode));
	q->front=NULL;
	q->rear=NULL;
	return q; 
}

bool isEmpty(Queue q){
	return q->front==NULL;
}

void AddQ(ElementType item,Queue q){
	List node=(List)malloc(sizeof(struct TreeNode));
	node->Data=item;
	node->next=NULL;
	if(isEmpty(q)){
		q->front=node;
		q->rear=node; 
	}else{
		q->rear->next=node;
		q->rear=node;
	}
		
} 

ElementType deleteQ(Queue q){
	ElementType e;
	List last;	 
	if(isEmpty(q)){
		return -1;
	}else{
		last=q->front;
		if(q->front==q->rear){
			q->front=q->rear=NULL;
		}else{
			q->front=q->front->next;
		} 
		e=last->Data;
		free(last);
	}
	return e;
}



int main(){

	return 0;
}
