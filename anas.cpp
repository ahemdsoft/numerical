
#include <iostream>
using namespace std;

void insertionDescendingSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleDescendingSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionDescendingSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        swap(arr[i], arr[maxIdx]);
    }
}

int binarySearchDescending(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) high = mid - 1; // descending
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int arr[100], n, id;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the last digit of your student ID: ";
    cin >> id;

    int method = id % 3;

    if (method == 0) {
        selectionDescendingSort(arr, n);
        cout << "Sorted using Selection Sort (descending): ";
    } else if (method == 1) {
        bubbleDescendingSort(arr, n);
        cout << "Sorted using Bubble Sort (descending): ";
    } else {
        insertionDescendingSort(arr, n);
        cout << "Sorted using Insertion Sort (descending): ";
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    while (true) {
        cout << "Enter key to search: ";
        cin >> key;

        int index = binarySearchDescending(arr, n, key);
        if (index != -1) {
            cout << "We have found the key value at Index " << index << endl;
            break;
        } else {
            cout << "Sorry, Try Again" << endl;
        }
    }

    return 0;
}
