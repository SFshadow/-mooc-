#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 30

typedef struct SNode* Stack;
struct SNode{
	int top;
	int element[MAXSIZE];
};
Stack init();
void push(Stack s,int data);
int pop(Stack s);
int pre[MAXSIZE],in[MAXSIZE],post[MAXSIZE];
void post_travel(int preL,int inL,int postL,int N);

int main(){
	int N,data;
	int k=0,j=0;
	scanf("%d",&N);
	char c[10];
	Stack s=init();
	for(int i=0;i<2*N;i++){
		scanf("%s",&c);
		getchar();
		if(strcmp(c,"Push")==0){
			scanf("%d",&data);
			push(s,data);
			pre[k++]=data;
		}else{
			in[j++]=pop(s);
		}
	}
	post_travel(0,0,0,N);
	int first=1;
	for(int i=0;i<N;i++){
		if(first){
			printf("%d",post[i]);
			first=0;
		}else{
			printf(" %d",post[i]);
		}
	}
	
	return 0;	
}



Stack init(){
	Stack s=(Stack)malloc(sizeof(struct SNode));
	s->top=-1;
	return s;
}

//��ջ
void push(Stack s,int data){
	if(s->top==MAXSIZE-1){
		return;
	}else{
		s->element[++s->top]=data;
	}
}
int pop(Stack s){
	if(s->top==-1){
		return -1;
	}
	return s->element[s->top--];
}

void post_travel(int preL,int inL,int postL,int N){/**preL,inL,postL�ֱ�����ŵ�ǰ����������**/ /***pre,in,post�ֱ������ǰ���У��������������***/ 
	int root,i,Left,Right;
	if(N==0){  /**û�и�����ʱ��ֱ�ӷ���**/ 
		return;
	}
	if(N==1){  /**���ݹ�ֻʣһ����ʱ��ǰ������ľ�����������Ľ��**/ 
		post[postL]=pre[preL];
		return;
	}
	root=pre[preL]; /**ǰ�����������˾���ÿ�εݹ�ĸ��ڵ�***/ 
	post[postL+N-1]=root;/**�ں�������Ľ���У����ڵ��������ʵ�***/ 
	for(i=0;i<N;i++){   /**������������ҵ����ڵ�**/ 
		if(root==in[inL+i]){
			break;
		}
	}
	Left=i;
	Right=N-Left-1;
	post_travel(preL+1,inL,postL,Left);  //�ݹ��������� 
	post_travel(preL+Left+1,inL+Left+1,postL+Left,Right); //�ݹ��������� 
	 
} 
 
