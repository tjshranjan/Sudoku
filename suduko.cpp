#include<bits/stdc++.h>
#include "template.h"
using namespace std;

void printsuduko(int arr[][9]){
    fo(i,9){
        fo(j,9){
            cout<<arr[i][j]<<" ";
        }
        cline;
    }
    exit(0);
    cline;
    cline;
}
bool isPossible(int grid[][9],int row,int col,int num){
     for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
 
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
 

    int startRow = row - row % 3,
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                            startCol] == num)
                return false;
 
    return true;
}

void solvesuduko(int arr[][9],int row,int col){
    if(row==8 && col==9){
        printsuduko(arr);
    }
    if(col==9){
        row++;
        col=0;
    }
    if(arr[row][col]>0){
        solvesuduko(arr,row,col+1);
    }
    for(int i=1;i<=9;i++){
        if(isPossible(arr,row,col,i)){
            arr[row][col]=i;
            solvesuduko(arr,row,col+1);
            arr[row][col]=0;
        }
    }
}
int main(){
   int arr[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                  {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                  {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                  {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                  {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                  {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                  {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                  {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                  {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solvesuduko(arr,0,0);
    return 0;
}