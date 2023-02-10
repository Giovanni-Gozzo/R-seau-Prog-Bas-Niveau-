#include <string.h>
#include <stdio.h>

int maximum(int *t, int n){
    int res=t[0];
    for(int i=0;i<n;i++){
        if(t[i]>res){
            res=t[i];
        }
    }
    return res;
}
int minimum(int *t, int n){
    int res=t[0];
    for(int i=0;i<n;i++){
        if(t[i]<res){
            res=t[i];
        }
    }
    return res;
}
void minmax(int *t, int n, int *pmin, int *pmax){
    *pmax=maximum(t,n);
    *pmin= minimum(t,n);
}
int main(){
    int t[]= {1,2,3,4,5,6,7,8,9,10};
    int pmin;
    int pmax;
    minmax(t,10,&pmin,&pmax);
    printf("%d %d",pmax,pmin);
}