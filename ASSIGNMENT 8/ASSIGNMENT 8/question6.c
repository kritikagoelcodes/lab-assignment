#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int t = *a; *a = *b; *b = t;
}

// Insert → Min Heap
void insert(int x){
    int i = size++;
    heap[i] = x;

    while (i != 0 && heap[(i-1)/2] > heap[i]){
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Remove minimum
int removeMin(){
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i){
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return root;
}

int main(){
    insert(30);
    insert(10);
    insert(50);
    insert(5);

    printf("Removed elements in priority order: ");
    while (size > 0)
        printf("%d ", removeMin());

    return 0;
}
