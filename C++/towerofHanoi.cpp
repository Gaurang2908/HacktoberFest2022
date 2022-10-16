#include<iostream>
using namespace std;

const char a = 'a',b = 'b',c = 'c';

void toh(int n,char f,char s,char t) {
    if (n==1) {
        printf("move disk 1 from %c to %c\n",f,t);
        return ;
    }
    toh(n-1,f,t,s);
    printf("move disk %d from %c to %c \n",n,f,t);
    toh(n-1,s,f,t);
}

int main() {
    int n;
    cout<<"enter the number of disks: "<<endl;
    cin>>n;
    toh(n,a,b,c);
    return 0;
}
