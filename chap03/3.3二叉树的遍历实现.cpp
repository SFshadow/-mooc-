#inclue<stdio.h>
#inclue<stdlib.h>
#define ElementType int
#define MaxSize 10000

typedef struct Node *TreeList;
typedef TreeList Position;
typedef strcut Node{
	ElementType data;
	TreeList children;
	TreeList brother;
}; 
/******************************************************************************�ݹ�ʵ��****************************************************************************////// 
/***�������**/
void PreOrderTraversal(TreeList Position){
	if(Position){
		printf("%d ",Position->data);
		PreOrderTraversal(Position->children);
		PreOrderTraversal(Position->brother);
	}
}

///**�������**
void InOrderPreTravel(TreeList Position){
	if(Position){
		InOrderPreTravel(Position->children);
		printf("%d ",Position->data);
		InOrderPreTravel(Position->brother);
	}
}

//**�������
 void PostOrderPreTravel(TreeList Position){
	if(Position){
		PostOrderPreTravel(Position->children);
		PostOrderPreTravel(Position->brother);
		printf("%d ",Position->data);
	}
}

//////////////////////////*********************************************��ջʵ��******************************************************************///
void PreOrderTraversal2(TreeList Position){
	TreeList T=Position;
	Stack s=CreatStack(MaxSize);
	while(T||!IsEmpty(s)){
		while(T){
			printf("%d ",T->data);
			push(s,T);
			T=T->children;
		}
		if(!IsEmpty(s)){
			T=pop();
			T=T->brother;
		} 
	}
}

void InOrderPreTravel2(TreeList Position){
	TreeList T=Position;
	Stack s=CreatStack(MaxSize);
	while(T||!IsEmpty(s)){
		while(T){
			push(s,T);
			T=T->children;
		}
		if(!IsEmpty(s)){
			T=pop();
			printf("%d ",T->data);
			T=T->brother;
		} 
	}
}

//*���ø���������������Ȼ��������� 
void PostOrderPreTravel2(TreeList Position){
	TreeList T=Position;
	Stack s=CreatStack(MaxSize);
	Stack s2=CreatStack(MaxSize);
	while(T||!IsEmpty(s)){
		while(T){
			printf("%d ",T->data);
			push(s,T);
			T=T->brother;
		}
		if(!IsEmpty(s)){
			T=pop();
			push(T,s2);
			T=T->children;
		} 
	}
}

///*******************************************************************************ʹ�ö���**********************************************************////
//��α��� 
void LevelOrderTravel(TreeList Positon){
	TreeList T=Position;
	Queue Q;
	if(!T) return;
	Q=CreateQueue(Maxsize);
	Add(Q,T);
	while(!isEmpty(Q)){
		T=DeleteQ(Q);
		if(T->children) Add(T->children,Q);
		if(T->brother) 	Add(T->brother,Q);
		printf("%d " T->data); 
	}
} 
