#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,2,2,3,4,5,6,7,8}; 
    int length = 10;
    int myTarget = 2;

    int s = 0, l = length - 1;
    int foundIndex = -1;
    while (s <= l) {
        int mid = (s + l) / 2;

        if (arr[mid] == myTarget) {
            foundIndex = mid;
            break;
        }
        else if (arr[mid] < myTarget) {
            s = mid + 1;
        }
        else {
            l = mid - 1;
        }
    }
    if (foundIndex != -1) {
        cout << "Duplicates found at indices: ";
        int i = foundIndex;
        while (i >= 0 && arr[i] == myTarget) {
            i--;
        }

        i++;
        while (i < length && arr[i] == myTarget) {
            cout << i << " ";
            i++;
        }
    }
    else {
        cout << "Element not found";
    }

    return 0;
}
