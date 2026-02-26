#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)


{
    int count=0;
    bool swapped=false;
    for(int i = 0; i < n-1; i++) 
    {
        swapped = false;
        for(int j = 0; j < n-1-i; j++) 
        {
            if(arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
                cout<<count<<endl;
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main() 
{
    int arr[] = {5, 1, 4, 2, 8};
    int n = 5;

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}