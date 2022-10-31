#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=n;j>=n-i;j--){
            cout<<j<<" ";
        }
        for(int j=1;j<=2*(n-i)-1;j++){
            cout<<"  ";
        }
        for(int j=n-i;j<=n;j++){
            if(j!=0)
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            cout<<j<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"  ";
        }
        for(int j=i;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
