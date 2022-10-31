#include<iostream>
using namespace std;
int main(){
signed long num1=0;
cout<<"Input a number:";
cin>>num1;
if(num1>0){
    cout<<"The number is positive";
}
else if(num1<0){
cout<<"The number is negative";
}
else{

    cout<<"The number is zero";
}

return 0;
}
