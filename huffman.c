#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
        char ch;
        int freq;
        struct Node *left;
        struct Node *right;
}node;

node * heap[100];
int HEAP_SIZE=0;

void Insert(node * element)
{
        HEAP_SIZE++;
        heap[HEAP_SIZE] = element;
        int point = HEAP_SIZE;
       	printf("\nHeap[%d] = %d insert : %d \n",point/2,heap[point/2]->freq,element->freq);
	    while(heap[point/2] -> freq > element -> freq)
        {
                heap[point] = heap[point/2];
                point /= 2;
        }
        heap[point] = element;
}
node * DeleteMin()
{
        node * min,*last;
        int child,point;
        min = heap[1];
        last = heap[HEAP_SIZE--];
        for(point = 1; point*2 <= HEAP_SIZE ;point = child)
        {
             child = point*2;
                 if(child != HEAP_SIZE && heap[child+1]->freq < heap[child] -> freq )
                {
                        child++;
                }
                if(last -> freq > heap[child] -> freq)
                {
                        heap[point] = heap[child];
                }
                else
                {
                        break;
                }
        }
        heap[point] = last;
        return min;
}
void print(node *temp,char *code)
{
        if(temp->left==NULL && temp->right==NULL)
        {
                printf("char %c : %s\n",temp->ch,code);
                return;
        }
        int length = strlen(code);
        char leftcode[10],rightcode[10];
        strcpy(leftcode,code);
        strcpy(rightcode,code);
        leftcode[length] = '0';
        leftcode[length+1] = '\0';
        rightcode[length] = '1';
        rightcode[length+1] = '\0';
        print(temp->left,leftcode);
        print(temp->right,rightcode);
}
int main()
{
       heap[0] = (node *)malloc(sizeof(node));
        heap[0]->freq = 0;
        int n ;
        printf("Enter the no of characters: ");
        scanf("%d",&n);
        printf("Enter the characters and their frequencies: ");
        char ch;
        int freq,i;

        for(i=0;i<n;i++)
        {
                scanf(" %c",&ch);
                scanf("%d",&freq);
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = ch;
                temp -> freq = freq;
                temp -> left = temp -> right = NULL;
                Insert(temp);
        }
        if(n==1)
        {
                printf("char %c : 0\n",ch);
                return 0;
        }
        for(i=0;i<n-1 ;i++)
        {
                node * left = DeleteMin();
                node * right = DeleteMin();
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = 0;
                temp -> left = left;
                temp -> right = right;
                temp -> freq = left->freq + right -> freq;
                Insert(temp);
        }
        node *tree = DeleteMin();
        char code[10];
        code[0] = '\0';
        print(tree,code);
}

