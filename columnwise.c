#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool issafe(int n,int b[n][n],int r,int c){
    for(int j=c-1;j>=0;j--)
    if(b[r][j]==1)
    return false;
    for(int i=r-1,j=c-1;i>=0,j>=0;i--,j--)
    if(b[i][j]==1)
    return false;
    for(int i=r+1,j=c-1;i<n,j>=0;i++,j--)
    if(b[i][j]==1)
    return false;
    return true;
}
bool placeq(int n,int b[n][n],int col){
    if(col>=n)
    return true;
    for(int i=0;i<n;i++){
        if(issafe(n,b,i,col))
        {b[i][col]=1;
        if(placeq(n,b,col+1))
        return true;
        b[i][col]=0;
        }
    }
    return false;
}
void printboard(int n,int b[n][n]){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    printf("%d ",b[i][j]);
    printf("\n");}
}
int main()
{
    int n;
    scanf("%d",&n);
    int b[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    b[i][j]=0;
    if(placeq(n,b,0))
    printboard(n,b);
    else
    printf("No solution exists");
    return 0;
}
