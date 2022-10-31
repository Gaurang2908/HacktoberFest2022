#include<iostream>
using namespace std;

int main(){
    int n,a=0,b=1;
    cin>>n;
    int count =0;
    int temp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(count%2==0){
                cout<<a<<" ";
                a=a+b;
            }
            else if(count%2==1){
                cout<<b<<" ";
                b=b+a;
            }
            count++;
        }
        cout<<endl;
    }
    return 0;
}
