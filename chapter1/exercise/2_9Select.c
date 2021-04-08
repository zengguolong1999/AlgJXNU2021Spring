#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizedSelect(int *nums, int left, int right, int wantNth);
void randomizedQuickSort(int *nums, int left, int right);
int randomizedPartition(int *nums, int left, int right);
int randFromTo(int from, int to);
void swap(int *arr, int i, int j);
void pArr(int *arr, int len);
int partition(int *nums, int left, int right);
void quickSort(int *nums, int left, int right);

#define LENARR 10
int main() {
    //int unsortedArr[LENARR] = {
    //     235, 1, 7, 91, 198, 78, 101, 92, 234, 99,
    //};
    int arr[LENARR];
    srand(time(0));
    for (int i=0; i<LENARR; i++) {
        arr[i] = 5;
    }
    pArr(arr, LENARR);
    int wantNth = rand()%LENARR + 1;
    randomizedSelect(arr, 0, LENARR-1, wantNth);
    printf("want: %d\n", wantNth);
    pArr(arr, LENARR);
}

void quickSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = partition(nums, left, right);
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

void randomizedQuickSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = randomizedPartition(nums, left, right);
    randomizedQuickSort(nums, left, i-1);
    randomizedQuickSort(nums, i+1, right);
}

int randomizedPartition(int *nums, int left, int right) {
    int i = randFromTo(left, right-1);
    swap(nums, left, i);
    return partition(nums, left, right);
}

// randomizedSelect will return the nth number indicated by "wantNth".
int randomizedSelect(int *nums, int left, int right, int wantNth) {
    if (left == right) { // Is this the real break out point?
        return nums[left];
    }
    pArr(nums, LENARR);
    int bound = randomizedPartition(nums, left, right);
    int lElementCount = bound-left+1;
    if (wantNth <= lElementCount) {
        if (bound == right) {
            if (lElementCount == wantNth) {
                return nums[right];
            } else {
                return randomizedSelect(nums, left, bound-1, wantNth);
            }
        }
        return randomizedSelect(nums, left, bound, wantNth);
    } else {
        return randomizedSelect(nums, bound+1, right, wantNth-lElementCount);
    }
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

// randFromTo will return a random integer from "from" to "to".
int randFromTo(int from, int to) {
    return rand()%(to-from+1) + from;
}
