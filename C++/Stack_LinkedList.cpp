//Implement stack using Linked list
#include<bits/stdc++.h>
using namespace std;

struct Node{
   int data;
   Node *next;
}*top=NULL;   //global variable

void push(int x){
    Node *temp = new Node;
    
    if(temp==NULL) cout<<"Stack is full"<<endl;

    else 
    {
        temp->data=x;
        temp->next=top;
        top=temp;
    }
}

int pop(){
    Node *temp;
    int x=-1;
    if(top==NULL) cout<<"Stack is empty"<<endl;

    else{
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);

    }
    return x;
}

void display(){
    struct Node *p;
    p=top;
    while(p){
        cout<<p->data<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    cout<<pop();
    return 0;
}
