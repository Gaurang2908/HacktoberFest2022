//Program to implement stack using array
#include<iostream>
#include<stdio.h>
using namespace std;
struct Stack{ 
  int size;
  int top;
  int *s;
};
void create(struct Stack *st){
    printf("Enter size\n ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int*) malloc (st->size*sizeof(int));
}
void display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d\t",st.s[i]);
    }
    printf("\n");
}
void push(struct Stack *st,int x){
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
    }
    else {
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(Stack *st){
    int x=-1;
    if(st->top==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        x=st->s[st->top];  //x=st->s[st->top--];
        st->top--;
    }
    return x;
}
int peek(Stack st,int pos){
    int x=-1;
    if(st.top-pos+1<0){
        cout<<"Invalid position\n";
    }
    else x=st.s[st.top-pos+1];
    return x;
}
int isEmpty(Stack st){
    if(st.top==-1){
        return 1;
    }
    else return 0;
}

int isFull(Stack st){
    if(st.top==st.size-1){
        return 1;
    }
    else return 0;
}

int StackTop(Stack st){
    /*if(st.top==-1){
        return -1;
    }
    else return st.s[st.top];*/
    if(!isEmpty(st)){
        return st.s[st.top];
    }
    return -1;
}

int main(){
     Stack st;
     create(&st);

     push(&st,10);
     push(&st,20);
     push(&st,30);
     push(&st,40);
     //push(&st,50);
     //push(&st,60);
     printf("%d\n",peek(st,1));
     
     display(st);

     return 0;
}
