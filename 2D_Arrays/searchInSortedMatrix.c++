#include<iostream>
using namespace std;
void searchInSorted(int mat[][4],int n,int target){
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(mat[i][j]==target){
    //             cout<<i<<j;
    //         }
    //     }
    // }


    // staircase search method
    // use if row and col are sorted 
    int i=0,j=n-1;
    while(i<n && j>=0){
        if(mat[i][j]==target){
            cout<<i<<j;
            return ;
        }
        else if(mat[i][j] >target){
            j--;
        }
        else{
            i++;
        }
    } 
      
}
int main(){
    int matrix[][4]={
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48}, 
        {32,33,39,50}
    };
    searchInSorted(matrix,4,20);
}