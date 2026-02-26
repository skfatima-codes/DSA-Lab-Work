#include <iostream>
using namespace std;
#define SIZE 7
#define EMPTY -1
#define DELETED -2
int hashtable[SIZE];
void init(){
    for(int i=0;i<SIZE;i++){
        hashtable[i]=-1;
    }
}
int hashFunction(int key){
    return key % SIZE;
}

void insertKey(int key) {
    int index = hashFunction(key);
    int i = 1;

    while(hashtable[index] != EMPTY && hashtable[index] != DELETED) {
        index = (hashFunction(key) + i*i) % SIZE;
        i++;

        if(i == SIZE) {
            cout << "Table Full\n";
            return;
        }
    }

    hashtable[index] = key;
}

int searchKey(int key) {
    int index = hashFunction(key);
    int i = 1;

    while(hashtable[index] != EMPTY) {

        if(hashtable[index] == key)
            return index;

        index = (hashFunction(key) + i*i) % SIZE;
        i++;

        if(i == SIZE)
            break;
    }

    return -1;
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int i = 1;

    while(hashtable[index] != EMPTY) {

        if(hashtable[index] == key) {
            hashtable[index] = DELETED;
            return;
        }

        index = (hashFunction(key) + i*i) % SIZE;
        i++;

        if(i == SIZE)
            break;
    }
}

void display() {
    for(int i = 0; i < SIZE; i++)
        cout << hashtable[i] << " ";
    cout << endl;
}
int main(){
    init();
    insertKey(0);
    insertKey(7);
    insertKey(14);
    insertKey(21);
    display();
    cout<<"Search key"<<searchKey(21)<<endl;
    display();
    deleteKey(7);
    display();
    return 0;
}
