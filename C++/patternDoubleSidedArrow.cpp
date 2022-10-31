#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a=(n+1)/2;
    // cout<<a<<endl;
    for(int i=1;i<=a;i++){
        for(int j=a;j>i;j--){
            cout<<"    ";
        }
        for(int j=i;j>=1;j--){
            cout<<j<<" ";
        }
        for(int k=0;k<2*(i-1)-1;k++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            if(i>1)
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=a-1;i++){
        for(int j=1;j<=i;j++){
            cout<<"    ";
        }
        for(int j=a-i;j>=1;j--){
            cout<<j<<" ";
        }
        for(int j=2*(a-i-1);j>1;j--){
            cout<<"  ";
        }
        for(int j=1;j<=a-i;j++){
            if(i!=a-1)
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
