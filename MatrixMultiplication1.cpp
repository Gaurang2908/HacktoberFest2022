#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    
    int arr1[a][b];
    int arr2[b][c];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++){
            cin>>arr1[i][j];
        }
    }
    cout<<endl;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++){
            cin>>arr2[i][j];
        }
    }
    cout<<endl;
    int mul[a][c];
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++){
            mul[i][j] = 0;
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++){
            for (int k = 0; k < b; k++){
                mul[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    
    for (int i = 0; i < a; i++){
        for (int j = 0; j < c; j++){
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
