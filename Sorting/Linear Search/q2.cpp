#include <iostream>
using namespace std;

int main() {
    int array[7] = {23, 56, 67, 23, 89, 5, 23};
    int mytarget = 23;
    int count = 0;

    // Linear search
    for(int i = 0; i < 7; i++) {
        if(array[i] == mytarget) {
            count++;
        }
    }

    if(count > 0) {
        cout << "Element " << mytarget 
             << "occurs" << count << " times" << endl;
    } else {
        cout << "Element not found(oop)" << endl;
    }

    return 0;
}