#include<iostream>
#include<math.h>
using namespace std;
int main(){
/*int side;
float area;
cin>>side;
area=sqrt(3)/4*side*side;
cout<<"The area of equilateral triangle is :"<<area<<endl;*/
int p,r,t;
float si,ci,cp;
cin>>p;
cin>>r;
cin>>t;
si=(p*r*t)/100;
ci=p*pow((1+r/100),t)-p;	
    cp=p*pow((1+r/100),t);

cout<<"The simple interest is:"<<si<<endl;
cout<<"The compound interest is:"<<ci<<endl;
cout<<"The total amount after compound interest is:"<<cp<<endl;
return 0;






}
