#include <iostream>
using namespace std;
int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int i=start-1; //pointer for small numbers
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    // now we place pivot at correct position
    swap(arr[i+1],arr[end]);
    return i+1; //return pivot index
}
void quicksort(int arr[],int start,int end){
    if(start<end){
        int pivotindex=partition(arr,start,end);
        //left (smaller than pivot)
        quicksort(arr,start,pivotindex-1);
        //right (larger than pivot)
        quicksort(arr,pivotindex+1,end);
    }
}
int main(){

    int arr[]={4,2,7,1,3};
    int n=5;
    cout<<"Original Array"<<endl;
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    quicksort(arr,0,n-1);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}