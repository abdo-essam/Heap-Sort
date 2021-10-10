#include <iostream>

using namespace std;

void heapify(int a[], int size, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check the largest node
    if (left < size && a[left] > a[largest])
        largest = left;

    // check the largest node
    if (right < size && a[right] > a[largest])
        largest = right;

    // Swap and continue reHeapify if root is not largest
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, size, largest);
    }
}

// main function to do heap sort
void heapSort(int a[], int n) {
    // Build max heap
    // In the case of a complete tree, the first index of a non-leaf node is given by n/2 - 1
    // All other nodes after that are leaf-nodes and thus don't need to be Heapified
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);

        // Heapify root element to get highest element at root again
        heapify(a, i, 0);
    }
}


int main() {
    int n;
    cout << "Enter number of elements you want :";
    cin >> n;
    int a[n];
    cout << "Enter elements :";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    heapSort(a, n);

    cout << "Sorted array is ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}