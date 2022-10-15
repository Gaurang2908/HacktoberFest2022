//fractional knapsack using greedy
#include<stdio.h>

struct data{
    int price;
    int weight;
    float r;
};

int main(){
    int cap;
    printf("Enter the capacity :");
    scanf("%d", &cap);

    int n, i, j;
    printf("Enter the number of objects :");
    scanf("%d", &n);

    struct data a[n];
    printf("Enter the price and weight of an object respectively\n");
    
    for(i=0; i<n; i++){
        scanf("%d %d", &a[i].price, &a[i].weight);
        a[i].r = (float) a[i].price/a[i].weight;
    }

    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(a[j].r < a[j+1].r){
                struct data temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    float ans = 0;
    for(i=0;  i<n && cap>0; i++){
        if ( cap >= a[i].weight ){
            ans += a[i].price;
            cap -= a[i].weight;
        }
        else if(cap > 0){
            ans += (float) cap/a[i].weight*a[i].price;
            cap =0;
        }
    }
    printf("The answer is %.2f", ans);
}
