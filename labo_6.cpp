// Example program
#include <iostream>
#include <string>
using namespace std;
#define n 5

int fastestWay(int a[2][n], int t[2][n], int e[2], int x[2]){

    int f = 0;
    int f1[n], f2[n];
    string p1[n];
    
    
    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][1];
    
    
    
    for(int i=1;i<=n; i++){
        
        if(f1[i-1] + a[0][i] <= f2[i-1] + t[1][i-1] + a[0][i]){
            f1[i] = f1[i-1] + a[0][i];    
        }
        else{
            f1[i] = f2[i-1] + t[1][i-1] + a[0][i];
        }
        
        if(f2[i-1] + a[1][i] <= f1[i-1] + t[0][i-1] + a[1][i]){
            f2[i] = f2[i-1] + a[1][i];
        }
        else{
            f2[i] = f1[i-1] + t[0][i-1] + a[1][i];    
        }
    }
    
    if(f1[n] + x[0] <= f2[n] + x[1]){
        return f = f1[n] + x[1];
    }
     
    return f = f2[n] + x[0];
    
    
    
};

int main()
{
    int a[2][5]={{1,2,5,4,6},{1,2,3,4,5}},t[2][5]={{1,2,5,4,6},{1,2,3,4,5}};
    int e[2]={4,5},x[2]={7,2};
    

    cout<<fastestWay(a,t,e,x);

}
