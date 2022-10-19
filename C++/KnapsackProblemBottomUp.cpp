#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
int t[N+1][N+1];
int knapsack(int n , int wt[] , int val[] , int wt1)
{
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<wt1+1 ; j++)
        {
            if(i==0 || j==0) t[i][j]=0; // if the either of the states is zero then the maximum cost will be zero
            if(wt[i-1]<=j)
            {
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][wt1]);
            }
            else{
                t[i][wt1] = t[i-1][wt1];
            }  
        }
    }
    return t[n][wt1];
}
int main()
{
    memset(t,-1,sizeof(t)); // initializing the value with invalid value so that we know if a valid input is there in a
    // state of n,wt
    int n;
    cin>>n;
    int wt[n] , val[n];
    for(int i=0 ; i<n ; i++) cin>>wt[i];
    for(int i=0 ; i<n ; i++) cin>>val[i];
    int w; // sum of the weight
    cin>>w;
    cout<<knapsack(n,wt,val,w);
}