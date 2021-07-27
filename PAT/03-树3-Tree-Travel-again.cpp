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

//入栈
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

void post_travel(int preL,int inL,int postL,int N){/**preL,inL,postL分别代表着当前数组的最左端**/ /***pre,in,post分别代表着前，中，后序遍历的数组***/ 
	int root,i,Left,Right;
	if(N==0){  /**没有个数的时候直接返回**/ 
		return;
	}
	if(N==1){  /**当递归只剩一个数时，前序遍历的就是中序遍历的结果**/ 
		post[postL]=pre[preL];
		return;
	}
	root=pre[preL]; /**前序遍历的最左端就是每次递归的根节点***/ 
	post[postL+N-1]=root;/**在后序遍历的结果中，根节点是最后访问的***/ 
	for(i=0;i<N;i++){   /**在中序遍历中找到根节点**/ 
		if(root==in[inL+i]){
			break;
		}
	}
	Left=i;
	Right=N-Left-1;
	post_travel(preL+1,inL,postL,Left);  //递归解决左子树 
	post_travel(preL+Left+1,inL+Left+1,postL+Left,Right); //递归解决右子树 
	 
} 
 
