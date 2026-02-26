#include <iostream>
using namespace std;
bool linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==mykey){
            return true;

        }
    }
    return false;
}
int main(){
    int arr[4]={1,2,4,5};
    int mykey;
    cin>>mykey;
    bool found=linearSearch(arr,4,mykey);
    if(found){
        cout<<"Key is in the array"<<endl;
    }else{
        cout<<"404 Error"<<endl;
    } 
    return 0;   
    }


