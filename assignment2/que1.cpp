#include <iostream>
using namespace std;

int bs(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] < key) {
            start = mid + 1; 
        } else {
            end = mid - 1;   
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key = 10;

    int result = bs(arr, n, key);
    if (result != -1)
        cout << "Index for the key is: " << result << endl;
    else
        cout << "Key not found" << endl;

    return 0;
}
