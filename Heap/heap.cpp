#include <iostream>
using namespace std;
#define MAX_SIZE 100 //size of heap

struct MaxHeap {
    int arr[MAX_SIZE];
    int size;
};

// swap function for heapify operations
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Up-Heapify (used for insertion)
void heapifyUp(MaxHeap &h, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && h.arr[index] > h.arr[parent]) {
        swap(h.arr[index], h.arr[parent]);
        heapifyUp(h, parent);
    }
}

// Down-Heapify (used for deletion)
void heapifyDown(MaxHeap &h, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    ////whether left child is larger than root

    if (left < h.size && h.arr[left] > h.arr[largest])
        largest = left;
        //whether right child is larger

    if (right < h.size && h.arr[right] > h.arr[largest])
        largest = right;
        // If largest is not root then we use swap ing

    if (largest != index) {
        swap(h.arr[index], h.arr[largest]);
        heapifyDown(h, largest);
    }
}

// inserting value into heap
void insert(MaxHeap &h, int value) {
    if (h.size == MAX_SIZE) {
        cout << "Heap Overflow!\n";
        return;
    }
    h.arr[h.size] = value;
    h.size++;
    heapifyUp(h, h.size - 1);
}

// deleting root maximum value
void deleteRoot(MaxHeap &h) {
    if (h.size <= 0) return;
    h.arr[0] = h.arr[h.size - 1];
    h.size--;
    heapifyDown(h, 0);
}

// displaying heap
void showHeap(MaxHeap &h) {
    for (int i = 0; i < h.size; i++)
        cout << h.arr[i] << " ";
    cout << "\n";
}

int main() {
    MaxHeap heap;
    heap.size = 0; // INTIALLY,size is 0

    int values[] = {11, 52, 78, 17, 92, 16, 22, 87, 99, 10};
    int n = 10;

    for (int i = 0; i < n; i++)
        insert(heap, values[i]);

    cout << "Max Heap: ";
    showHeap(heap);

    deleteRoot(heap);
    cout << "After deleting root: ";
    showHeap(heap);

    return 0;
}