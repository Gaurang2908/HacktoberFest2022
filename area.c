// Takes something returns nothing
#include<stdio.h>
#include<conio.h>
void main()
{
    int x,y;
    void mul(int,int);           // in declaration statement return(data type) type is written first 
    printf("Enter length and breadth ");
    scanf("%d%d",&x,&y);
    mul(x,y);  // x and y values passes in mul function which gets copied in a and b also called call by value
              // and actual arguments
    getch();

}
void mul(int a,int b)   // in function definition each variable has to be declared separately formal arguments
{
    int c;
    c=a*b;
    printf("Area = %d ",c);
}