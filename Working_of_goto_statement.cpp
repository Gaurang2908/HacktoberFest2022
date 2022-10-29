#include<iostream>
using namespace std;
int main()
{float marks;
label : cout<<"Enter the marks : ";
cin>>marks;
if(marks<0||marks>100)
{cout<<"Not a valid marks\n";
goto label;
}
else
{cout<<"The Entered marks is : "<<marks;
}
return 0;
}
