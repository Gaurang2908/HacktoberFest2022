#include <stdlib.h>
#include <stdio.h>

struct node
{
    int inform;
    struct node *link;
};
struct node *start = NULL;
// user defined function to create linked list with adding num
struct node *create(struct node *point, int num)
{
    struct node *fun;
    int num1, i;
    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL) // for underflow case
    {
        printf("Memory can't be allocated.\n");
    }
    else
    {
        printf("Given input data for node 1 : ");
        scanf("%d", &num1);
        start->inform = num1;
        start->link = NULL; // links the address field to NULL
        point = start;
        for (i = 2; i <= num; i++)
        {
            fun = (struct node *)malloc(sizeof(struct node));
            printf("Given input data for node %d : ", i);
            scanf(" %d", &num1);
            fun->inform = num1; // links the num field of fnNode with num
            fun->link = NULL;   // links the address field of fnNode with NULL
            point->link = fun;  // links previous node i.e. tmp to the fnNode
            point = point->link;
        }
    }
}
// user defined function to display the input data
struct node *display(struct node *point)
{
    if (start == NULL) // for underflow case
    {
        printf("List is empty.\n");
    }
    printf("Starting data list address is : %u\n", start); // printing address
    point = start;                                         // pointing start base address of data1
    int i = 1;
    while (point != NULL)
    {
        printf("The value at node %d is:%d\n", i, point->inform); // prints the data of entered node
        point = point->link;                                      // advances the position of entered node
        i++;
    }
}
// user define function to insert data at first
struct node *infirst(struct node *point, int val)
{
    if (start == NULL)
    {
        printf("List is empty.");
    }
    struct node *avail;

    avail = (struct node *)malloc(sizeof(struct node));

    if (avail == NULL)
        printf("OVERFLOW");
    avail->inform = val;
    avail->link = start;
    start = avail;
    printf("Data is inserted in the begining\n");
}
// user define function to insert data at end
struct node *insend(struct node *point, int val)
{
    struct node *avail;
    avail = (struct node *)malloc(sizeof(struct node));

    if (avail == NULL)
        printf("OVER FLOW");
    avail->inform = val;
    avail->link = NULL;
    point = start;
    while (point != NULL && point->link != NULL)
        point = point->link;

    point->link = avail;
    printf("Data is inserted in the end\n");
}
// user define function to count data
struct node *count(struct node *point)
{
    int sum = 0;
    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    point = start;
    while (point != NULL)
    {
        sum++;
        point = point->link;
    }
    printf("\nTotal number in the given list: %d\n", sum);
}
// user define function to delete data from first
struct node *delfirst(struct node *point)
{
    struct node *avail;
    if (start == NULL)
        printf("UNDERFLOW");
    point = start;
    start = start->link;
    point->link = avail;
    avail = point;
    printf("Data is deleated from the begining\n");
}
// user define function to delete data from end
struct node *delend(struct node *point)
{
    struct node *avail;
    if (start == NULL)
        printf("UNDER FLOW");
    point = start;
    while (point->link != NULL)
    {
        avail = point;
        point = point->link;
    }
    avail->link = NULL;
    point->link = avail;
    avail = point;
    printf("Data is deleated from the end\n");
}

int main()
{
    struct node *point;
    int choice, num, value, add;
    printf("Enter the number of nodes you want to enter:\n");
    scanf("%d", &num);
    create(point, num);
    while (1)
    {
        printf("Enter 1 to display the data you entered.\n");
        printf("Enter 2 to insert data at the beginning.\n");
        printf("Enter 3 insert data at the end.\n");
        printf("Enter 4 to counting the number of data you entered.\n");
        printf("Enter 5 to delete data from beginning.\n");
        printf("Enter 6 to delete data from the end.\n");
        printf("Enter 7 tO EXIT/END.\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice); // taking input
        printf("\n\n");
        switch (choice)
        {
        case 1:
            display(point); // using user defined fun
            break;
        case 2:
            printf("Enter the value to add in the data list at beginning:");
            scanf("%d", &value);   // taking value to enter in list at beginning
            infirst(point, value); // using user defined fun
            break;
        case 3:
            printf("Enter the value to add in the data list at end:");
            scanf("%d", &value);  // taking value to enter in list at end
            insend(point, value); // using user defined fun
            break;
        case 4:
            count(point); // using user defined fun
            break;
        case 5:
            delfirst(point); // using user defined fun
            break;
        case 6:
            delend(point); // using user defined fun
            break;
        case 7:
            exit(0); // ending our program
        default:
            printf("\n Wrong Choice:\n"); // for any other input
            break;
        }
    }
    return 0;
}