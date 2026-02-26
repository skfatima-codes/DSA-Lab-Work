#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int length = 8;
    int myTarget = 2;
    cin>>"enter the "
    int s = 0;
    int l = length - 1;

    while (s <= l) {
        int mid = (s + l) / 2; 

        if (arr[mid] == myTarget) {
            cout << "Element found at index " << mid << endl;
            return 0;
        }
        else if (arr[mid] < myTarget) {
            s = mid + 1;
        }
        else {
            l = mid - 1;
        }
    }

    cout << "Not found" << endl;
    return 0;
}
