#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++; 
            swap(arr[i],arr[j]);
            cout<<arr[i];
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

int quicksort(int arr[],int s,int e){
    if(s<e){
        int pIdx=partition(arr,s,e);
        quicksort(arr,s,pIdx-1);
        quicksort(arr,pIdx+1,e);
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] ={10,7,8,9,1,5};
    int n = 6;
    quicksort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}