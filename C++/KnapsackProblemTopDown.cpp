#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
int t[N+1][N+1];
int knapsack(int n , int wt[] , int val[] , int weight)
{
    if(n==0 || weight == 0) return 0;
    if(t[n][weight]!=-1) return t[n][weight]; // if the array values is not zero which means it is already has that value
    // before and that subproblem is already solved
    if(wt[n-1] <= weight)
    {
        t[n][weight] = max(val[n-1]+knapsack(n-1,wt,val,weight-wt[n-1]),knapsack(n-1,wt,val,weight));
        // there are two choices for weight less than the int weight passed as a parameter 
    }
    else{
        t[n][weight] = knapsack(n-1,wt,val,weight); // if the weight is greather than sum adding it would be useless
    }
    return t[n][weight];
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
