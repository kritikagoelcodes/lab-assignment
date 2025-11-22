#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to count size of circular linked list
int sizeCircular(struct Node* head) {
    if (head == NULL)
        return 0;

    int count = 0;
    struct Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Create sample circular linked list for testing
struct Node* createSampleCLL() {
    int arr[] = {20, 100, 40, 80, 60};
    int n = 5;

    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head; // Make it circular

    return head;
}

int main() {
    struct Node* head = createSampleCLL();

    printf("Size of Circular Linked List: %d\n", sizeCircular(head));

    return 0;
}
