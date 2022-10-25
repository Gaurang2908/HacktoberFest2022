// TAKES NOTHING RETURNS NOTHING

#include<stdio.h>
#include<conio.h>   // console input output

void main()
{
    void add(void);            // FUNCTION DECLARATION
    add();                     // FUNCTION CALL
    getch();
}

void add()                 // FUNCTION DEFINITION
    {
        int a,b,c;
        printf("Enter two numbers ");
        scanf("%d%d",&a,&b);
        c=a+b;
        printf("Sum is %d",c);
        
    }
    // Declaration statement execution k time nahi, chalte compilation k time kaam k hote hai
    
    
