#include <iostream>
using namespace std;
#define SIZE 7
#define EMPTY -1
#define DELETED -2
int hashtable[SIZE];
void init(){
    for(int i=0;i<SIZE;i++){
        hashtable[i]=EMPTY;
    }
}
int hashfunction(int key){
    return key%SIZE;
}
void insert(int key){
    int idx=hashfunction(key);
    while(hashtable[idx]!=-1 && hashtable[idx]!=-2){
        idx=(idx+1)%SIZE;
        // return idx;
    }
    hashtable[idx]=key;

}
int search(int key){
    int idx=hashfunction(key);
    int start=idx;
    while(hashtable[idx]!=-1){
        if(hashtable[idx]==key){
            return idx;
            // idx=(idx+1)%SIZE;


        }
        idx=(idx+1)%SIZE;
        if(idx==start){
            break;
        }
    }
    return -1;
}
void delete_key(int key){
     int idx=hashfunction(key);
    int start=idx;
    while(hashtable[idx]!=-1){
        if(hashtable[idx]==key){
            hashtable[idx]=-2;
            return;
            
        }
          idx=(idx+1)%SIZE;
          if(start==idx){
            break;
          }
    }
}
void display(){
    for(int i=0;i<SIZE;i++){
        cout<<hashtable[i]<<" ";
    }
    cout<<endl;
}

int main(){
    init();
    insert(12);
    insert(13);
    insert(14);
    display();
    delete_key(17);
    display();
    cout<<"Searching the key "<<search(12)<<endl;
    display();
    return 0;
}