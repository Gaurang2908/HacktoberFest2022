#include<iostream>
using namespace std;
int findMax(int a, int b){
    int sum = a+b;
    int sub = abs(a-b);
    return (sum+sub)/2;
}
int main(){
    int a,b;
    cout<<"Enter a and b:";
    cin>>a>>b;
    cout<<"larger number is "<<findMax(a, b);
}
