#include <iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end){
    int size=end-start+1;
    //we make a temporay aray by dynamic memory allocation
    int*temp=new int[size];
    int i=start;//left pointer
    int j=mid+1;
    int k=0;//temporary array pointer
    //now we compare both halves
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    //copying remaining elements for left and right halves
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end){
        temp[k]=arr[j];
        j++;
        k++;
    }
    //copying temp to original array
    for(int x=0;x<size;x++){
        arr[start+x]=temp[x];
    }
    delete temp;//cleaning the memory

}
void mergesort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    //sort left merge
    mergesort( arr, start, mid);
    //right merge
    mergesort( arr,mid+1, end);
    //merge both halves
    merge(arr,start,mid,end);

}
int main(){
    int arr[]={6,3,9,1,5};
    int n=5;
    cout<<"Orignal Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    mergesort(arr,0,n-1);//recursive fun
    cout<<"\nAfter applying merge sort logic"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";


    }

}