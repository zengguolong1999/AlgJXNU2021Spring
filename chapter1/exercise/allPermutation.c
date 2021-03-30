#include <stdio.h>

void swap(int *arr, int i, int j);
void pArr(int *arr, int len);
void allPermutation(int *arr, int left, int right);

int
main() {
    int arr[10] = {
        1, 2, 3, 4
    };
    allPermutation(arr, 0, 3);
    return -1;
}


void allPermutation(int *arr, int left, int right) {
    if (left == right) {
        pArr(arr, right+1);
        return;
    }
    allPermutation(arr, left+1, right);
    for (int i=left+1; i<=right; i++) {
        swap(arr, left, i);
        allPermutation(arr, left+1, right);
        swap(arr, left, i);
    }
}

void pArr(int *arr, int len) { for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *arr, int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
