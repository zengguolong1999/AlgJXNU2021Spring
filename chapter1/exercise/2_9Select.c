#include <stdio.h>

void swap(int *arr, int i, int j);
void pArr(int *arr, int len);
int partition(int *nums, int left, int right);
void quickSort(int *nums, int left, int right);

#define LENARR 10
int main() {
    int unsortedArr[LENARR] = {
         235, 1, 7, 91, 198, 78, 101, 92, 234, 99,
    };
    pArr(unsortedArr, LENARR);
    quickSort(unsortedArr, 0, 9);
    pArr(unsortedArr, LENARR);
}

void quickSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = partition(nums, left, right);
    pArr(nums, LENARR);
    quickSort(nums, left, i-1);
    quickSort(nums, i+1, right);
}

int partition(int *nums, int left, int right) {
    int boundVal = nums[left];
    int leftI = left+1, rightI = right;
    while (1) {
        while (nums[leftI] <= boundVal && leftI < right) { //<= vs <
            leftI += 1;
        }
        while (nums[rightI] > boundVal) {
            rightI -= 1;
        }
        if (leftI >= rightI) {
            break;
        }
        swap(nums, leftI, rightI);
    }
    swap(nums, left, rightI);
    return rightI;
}

void pArr(int *arr, int len) { 
    for (int i=0; i<len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
