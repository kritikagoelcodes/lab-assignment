#include <iostream>
using namespace std;

#define MAX 100   
int arr[MAX];     
int n = 0;        

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Size exceeds maximum limit!" << endl;
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


void display() {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void insert() {
    if (n == MAX) {
        cout << "Array is full!" << endl;
        return;
    }
    int pos, val;
    cout << "Enter position (0-" << n << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
}


void deleteElement() {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    int pos;
    cout << "Enter position (0-" << n-1 << "): ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}


void linearSearch() {
    if (n == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found!" << endl;
}

int main() {
    int choice;
    do {
        cout << "\n—— MENU ——" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
